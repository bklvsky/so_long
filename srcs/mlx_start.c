/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:58:38 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 03:07:39 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_win_res(t_win *win)
{
	int		x_screen;
	int		y_screen;

	mlx_get_screen_size(win->mlx, &x_screen, &y_screen);
	if (win->map_x > x_screen)
	{
		win->flag_screen_x = 1;
		win->img->width = x_screen - x_screen % SCALE;
	}
	else
		win->img->width = win->map_x;
	if (win->map_y > y_screen)
	{
		win->flag_screen_y = 1;
		win->img->height = y_screen - y_screen % SCALE;
	}
	else
		win->img->height = win->map_y;
}

int	start_win(t_win *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (-1);
	get_win_res(win);
	win->img->img = mlx_new_image(win->mlx, win->img->width, win->img->height);
	if (!win->img->img)
		return (-1);
	win->img->addr = mlx_get_data_addr(win->img->img, &(win->img->bpp), \
								&(win->img->line_len), &(win->img->en));
	if (!win->img->addr || get_texture(win) < 0)
		return (-1);
	win->win = mlx_new_window(win->mlx, win->img->width, \
											win->img->height, "So_long");
	if (!win->win)
		return (-1);
	return (1);
}