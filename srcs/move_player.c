/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 01:57:19 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 03:08:00 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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