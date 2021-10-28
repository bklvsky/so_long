/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:39:23 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 02:37:29 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	is_on_screen(t_win *win, t_enemy enemy)
{
	return (enemy.win_x > win->start_draw_x * SCALE && \
	enemy.win_x < (win->start_draw_x * SCALE) + win->img->width && \
	enemy.win_y > win->start_draw_y * SCALE && \
	enemy.win_y < (win->start_draw_y * SCALE) + win->img->height);
}

void	put_enemies(t_win *win, t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemy_num)
	{
		if (game->enemy[i].pos_y == game->plr.pos_y && \
									game->enemy[i].pos_x == game->plr.pos_x)
			game->data[DATA_EXIT] = -1;
		if (is_on_screen(win, game->enemy[i]))
			put_square(win->img, win->enemy[game->enemy[i].state], \
			(game->enemy[i].win_x - win->start_draw_x * SCALE), \
			game->enemy[i].win_y - win->start_draw_y * SCALE);
		i += 1;
	}
}

int	print_moves(t_win *win, int moves)
{
	char	*str;
	char	*str_num;

	str_num = ft_itoa(moves);
	str = ft_strjoin("MOVES  ", str_num);
	if (!str_num || !str)
		return (0);
	mlx_string_put(win->mlx, win->win, 6, SCALE / 2, 0, str);
	free(str);
	free(str_num);
	return (1);
}
