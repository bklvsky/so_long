/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:58:38 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/21 03:52:31 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_res(t_win *win, char **map)
{
	win->map_x = (int)ft_strlen(*map) * SCALE;
	win->map_y = (int)ft_charmtrx_len(map) * SCALE;
}

void	get_win_res(t_win *win)
{
	int		x_screen;
	int		y_screen;

	mlx_get_screen_size(win->mlx, &x_screen, &y_screen);
	if (win->map_x > x_screen)
	{
		win->flag_screen_x = 1;
		win->img->width = x_screen;
	}
	else
		win->img->width = win->map_x;
	if (win->map_y > y_screen)
	{
		win->flag_screen_y = 1;
		win->img->height = y_screen;
	}
	else
		win->img->height = win->map_y;
//	printf("map_x = %d, map_y = %d, img_width = %d, img_height = %d\n", win->map_x, win->map_y, win->img->width, win->img->height);

	
//	printf("in getwinres\n");
//	printf("ft_strlen = %ld, ft_mtrx_len = %ld\n", ft_strlen(*map), ft_charmtrx_len(map));
//	printf("in get win res x_win = %d, y_win = %d\n", win->x_win, win->y_win);
}

int	get_tex_img(void *mlx, char *path, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &(tex->width), &(tex->height));
	if (!tex->img)
	{
		printf("sth wrong with texture in get_tex_img\n");
		perror("MLX error");
		return (0);
	}
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp),\
									 &(tex->line_len), &(tex->en));
	if (!tex->addr)
		return (0);
	return (1);
}

int	get_texture(t_win *win, t_img *tex_table)
{
	int		i;

	i = 0;
	while (i <= 4)
	{
		if (i == 0)
			get_tex_img(win->mlx, FLOOR_TEX_PATH, &tex_table[i]);
		else if (i == 1)
			get_tex_img(win->mlx, WALL_TEX_PATH, &tex_table[i]);
		else if (i == 2)
			get_tex_img(win->mlx, CLLCT_TEX_PATH, &tex_table[i]);
		else if (i == 3)
			get_tex_img(win->mlx, PLR_TEX_PATH, &tex_table[i]);
		else
			get_tex_img(win->mlx, EXIT_TEX_PATH, &tex_table[i]);
		if (!tex_table[i].img)
			return (0);
		i++;
	}
	return (1);
}

int	start_win(t_win *win)
{
//	int		x_screen;
//	int		y_screen;

	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	get_win_res(win);
//	mlx_get_screen_size(win->mlx, &x_screen, &y_screen);
//	printf("x_screen = %d, y_screen = %d\n x_win = %d, y_win = %d,", x_screen, y_screen, win->img->width, win->img->height);
//	if (win->img->width > x_screen || win->img->height > y_screen)
//		return (0);
	win->img->img = mlx_new_image(win->mlx, win->img->width, win->img->height);
	if (!win->img->img)
		return (0);
//	printf("got an image\n");
	win->img->addr = mlx_get_data_addr(win->img->img, &(win->img->bpp),\
								 &(win->img->line_len), &(win->img->en));
//	printf("line_len = %d, bpp = %d, endian = %d\n", win->img->line_len, win->img->bpp, win->img->en);
	if (!win->img->addr)
		return (0);
	if (!get_texture(win, win->tex_table))
		return (0);
	win->win = mlx_new_window(win->mlx, win->img->width, \
											win->img->height, "So_long");
	if (!win->win)
		return (0);
	return (1);
/*	WINDOW SIZE MANAGEMENT -- TO DO LATER	
	if (win->y_win > y_screen)
		win->y_win = y_screen;
	if (win->x_win > x_screen)
		win->x_win = x_screen;*/
//	win->img = mlx_new_image(win->mlx);
}