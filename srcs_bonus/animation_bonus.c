/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:59:04 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/26 02:36:13 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_enemy(t_enemy *enemy, char **map)
{
	if (map[enemy->pos_y + enemy->dir_y][enemy->pos_x + enemy->dir_x] != '0')
	{
		enemy->dir_x *= -1;
		enemy->dir_y *= -1;
	}
	enemy->win_x += enemy->dir_x * SCALE / EN_MOVES_FOR_SQUARE;
	enemy->win_y += enemy->dir_y * SCALE / EN_MOVES_FOR_SQUARE;
	enemy->state = (enemy->state + 1) % ENEMY_ANIMATION;
	if (enemy->win_x % SCALE == 0 && enemy->win_y % SCALE == 0)
	{
		enemy->pos_x += enemy->dir_x;
		enemy->pos_y += enemy->dir_y;
	}
}

void	move_enemies(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemy_num)
	{
		move_enemy(&(game->enemy[i]), game->map);
		if (game->enemy[i].pos_x == game->plr.pos_x && \
									game->enemy[i].pos_y == game->plr.pos_y)
		{
			printf("fuck you\n");
			game->data[DATA_EXIT] = -1;
		}
		i += 1;
	}
}