/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:41:23 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/22 22:20:54 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_start_pos(t_win *win, t_game *game)
{
	if (win->flag_screen_x == 0)
		win->start_draw_x = 0;
	else
	{
		if (game->plr_x * SCALE - win->img->width / 2 < 0)
			win->start_draw_x = 0;
		else if (game->plr_x * SCALE + win->img->width / 2 > win->map_x)
			win->start_draw_x = (win->map_x - win->img->width) / SCALE;
		else
			win->start_draw_x = game->plr_x - (win->img->width / 2 / SCALE);
	}
	if (win->flag_screen_y == 0)
		win->start_draw_y = 0;
	else
	{
		if (game->plr_y * SCALE - win->img->height / 2 < 0)
			win->start_draw_y = 0;
		else if (game->plr_y * SCALE + win->img->height / 2 > win->map_y)
			win->start_draw_y = (win->map_y - win->img->height) / SCALE;
		else
			win->start_draw_y = game->plr_y - (win->img->height / 2 / SCALE);
	}
}

void	put_map(t_win *win, char **map)
{
	int		y;
	int		x;

	y = -1;
	while (map[++y + win->start_draw_y])
	{
		x = -1;
		while (map[y + win->start_draw_y][++x + win->start_draw_x])
		{
			if (map[y + win->start_draw_y][x + win->start_draw_x] == '1')
			{
				put_square(win->img, win->texs[WALL], x * SCALE, y * SCALE);
				continue ;
			}
			put_square(win->img, win->texs[FLOOR], x * SCALE, y * SCALE);
			if (map[y + win->start_draw_y][x + win->start_draw_x] == '0')
				continue ;
			if (map[y + win->start_draw_y][x + win->start_draw_x] == 'C')
				put_square(win->img, win->texs[CLLCT], x * SCALE, y * SCALE);
			else if (map[y + win->start_draw_y][x + win->start_draw_x] == 'E')
				put_square(win->img, win->texs[EXIT], x * SCALE, y * SCALE);
		}
	}
}

void	put_player(t_win *win, t_game *game)
{
	put_square(win->img, win->texs[game->plr_dir], (game->plr_x -\
	 win->start_draw_x) * SCALE, (game->plr_y - win->start_draw_y) * SCALE);
}

void	render_game(char **map, t_game *game, t_win *win)
{
	mlx_do_sync(win->mlx);
	get_start_pos(win, game);
	put_map(win, map);
	put_player(win, game);
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
	if (game->exit == 0)
	{
		printf("CONGRATULATIONS, YOU WON WITH THE SCORE OF %d\n", game->moves);
	}
}

void	launch_game(t_data *all)
{
	get_map_res(all->win, all->map);
	if (!start_win(all->win))
		shutdown(all, "MiniLibX error", strerror(errno));
//	printf("started win w/o problems\n");
	render_game(all->map, all->game, all->win);
	mlx_key_hook(all->win->win, &handle_keys, all);
	mlx_hook(all->win->win, 17, (1L<<17), &stop_game, all);
	mlx_loop(all->win->mlx);
}
