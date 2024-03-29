/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:32:36 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 22:49:44 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	plr_up(t_game *game)
{
	if (game->map[game->plr.pos_y - 1][game->plr.pos_x] == '1')
		return (0);
	game->plr.pos_y -= 1;
	game->plr.dir = PLR_UP;
	move_player(game);
	return (1);
}

int	plr_down(t_game *game)
{
	if (game->map[game->plr.pos_y + 1][game->plr.pos_x] == '1')
		return (0);
	game->plr.pos_y += 1;
	game->plr.dir = PLR_DOWN;
	move_player(game);
	return (1);
}

int	plr_left(t_game *game)
{
	if (game->map[game->plr.pos_y][game->plr.pos_x - 1] == '1')
		return (0);
	game->plr.pos_x -= 1;
	game->plr.dir = PLR_LEFT;
	move_player(game);
	return (1);
}

int	plr_right(t_game *game)
{
	if (game->map[game->plr.pos_y][game->plr.pos_x + 1] == '1')
		return (0);
	game->plr.pos_x += 1;
	game->plr.dir = PLR_RIGHT;
	move_player(game);
	return (1);
}

void	move_player(t_game *game)
{
	game->moves += 1;
	if (game->map[game->plr.pos_y][game->plr.pos_x] == 'C')
	{
		game->map[game->plr.pos_y][game->plr.pos_x] = '0';
		game->data[DATA_CLLCT] -= 1;
	}
	else if (game->map[game->plr.pos_y][game->plr.pos_x] == 'E' && \
												game->data[DATA_CLLCT] == 0)
		game->data[DATA_EXIT] = 0;
}
