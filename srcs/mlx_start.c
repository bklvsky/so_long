/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:58:38 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/22 22:25:37 by dselmy           ###   ########.fr       */
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
}

int	get_tex_img(void *mlx, char *path, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &(tex->width), &(tex->height));
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp), \
									&(tex->line_len), &(tex->en));
	if (!tex->addr)
		return (0);
	return (1);
}

char	*get_tex_path(int i)
{
	if (i == FLOOR)
		return (FLOOR_TEX_PATH);
	else if (i == WALL)
		return (WALL_TEX_PATH);
	else if (i == CLLCT)
		return (CLLCT_TEX_PATH);
	else if (i == EXIT)
		return (EXIT_TEX_PATH);
	else if (i == PLR_UP)
		return (PLR_UP_PATH);
	else if (i == PLR_DOWN)
		return (PLR_DOWN_PATH);
	else if (i == PLR_LEFT)
		return (PLR_LEFT_PATH);
	else if (i == PLR_RIGHT)
		return (PLR_RIGHT_PATH);
	else
		return (NULL);
}

int	get_texture(t_win *win, t_img *tex)
{
	int		i;

	i = 0;
	while (i <= 7)
	{
		get_tex_img(win->mlx, get_tex_path(i), &tex[i]);
		if (!tex[i].img)
			return (0);
		i++;
	}
	return (1);
}

int	start_win(t_win *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	get_win_res(win);
	win->img->img = mlx_new_image(win->mlx, win->img->width, win->img->height);
	if (!win->img->img)
		return (0);
	win->img->addr = mlx_get_data_addr(win->img->img, &(win->img->bpp), \
								&(win->img->line_len), &(win->img->en));
	if (!win->img->addr || !get_texture(win, win->texs))
		return (0);
	win->win = mlx_new_window(win->mlx, win->img->width, \
											win->img->height, "So_long");
	if (!win->win)
		return (0);
	return (1);
}
