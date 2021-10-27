/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:41:23 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 01:10:41 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_start_pos(t_win *win, t_plr plr)
{
	if (win->flag_screen_x == 0)
		win->start_draw_x = 0;
	else
	{
		if (plr.pos_x * SCALE - win->img->width / 2 < 0)
			win->start_draw_x = 0;
		else if (plr.pos_x * SCALE + win->img->width / 2 > win->map_x)
			win->start_draw_x = (win->map_x - win->img->width) / SCALE;
		else
			win->start_draw_x = plr.pos_x - (win->img->width / 2 / SCALE);
	}
	if (win->flag_screen_y == 0)
		win->start_draw_y = 0;
	else
	{
		if (plr.pos_y * SCALE - win->img->height / 2 < 0)
			win->start_draw_y = 0;
		else if (plr.pos_y * SCALE + win->img->height / 2 > win->map_y)
			win->start_draw_y = (win->map_y - win->img->height) / SCALE;
		else
			win->start_draw_y = plr.pos_y - (win->img->height / 2 / SCALE);
	}
}

void	put_exit(t_win *win, t_game *game, int x, int y)
{
	if (game->data[DATA_CLLCT])
		put_square(win->img, win->env[EXIT_OFF], x, y);
	else
		put_square(win->img, win->env[EXIT_ON], x, y);
}

void	put_map(t_win *win, t_game *game)
{
	int		y;
	int		x;

	y = -1;
	while (game->map[++y + win->start_draw_y])
	{
		x = -1;
		while (game->map[y + win->start_draw_y][++x + win->start_draw_x])
		{
			if (game->map[y + win->start_draw_y][x + win->start_draw_x] == '1')
			{
				put_square(win->img, win->env[WALL], x * SCALE, y * SCALE);
				continue ;
			}
			put_square(win->img, win->env[FLOOR], x * SCALE, y * SCALE);
			if (game->map[y + win->start_draw_y][x + win->start_draw_x] == '0')
				continue ;
			if (game->map[y + win->start_draw_y][x + win->start_draw_x] == 'C')
				put_square(win->img, win->cllct[game->cllct_state], \
														x * SCALE, y * SCALE);
			else if (game->map[y + win->start_draw_y]\
												[x + win->start_draw_x] == 'E')
				put_exit(win, game, x * SCALE, y * SCALE);
		}
	}
}

void	put_player(t_win *win, t_plr plr)
{
	put_square(win->img, win->plr[plr.dir], (plr.pos_x - \
		win->start_draw_x) * SCALE, (plr.pos_y - win->start_draw_y) * SCALE);
}
