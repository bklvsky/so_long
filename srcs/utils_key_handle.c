/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:32:36 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/25 02:33:20 by dselmy           ###   ########.fr       */
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