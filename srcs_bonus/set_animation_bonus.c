/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:59:04 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 21:45:29 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_enemy(t_enemy *enemy, char **map)
{
	enemy->state = (enemy->state + 1) % ENEMY_ANIMATION;
	if (map[enemy->pos_y + enemy->dir_y][enemy->pos_x + enemy->dir_x] != '0')
	{
		enemy->dir_x *= -1;
		enemy->dir_y *= -1;
		return ;
	}
	enemy->win_x += enemy->dir_x * SCALE / EN_MOVES_FOR_SQUARE;
	enemy->win_y += enemy->dir_y * SCALE / EN_MOVES_FOR_SQUARE;
	if (enemy->win_x % SCALE == 0 && enemy->win_y % SCALE == 0)
	{
		enemy->pos_x += enemy->dir_x;
		enemy->pos_y += enemy->dir_y;
	}
}

static void	move_enemies(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemy_num)
	{
		move_enemy(&(game->enemy[i]), game->map);
		if (game->enemy[i].pos_x == game->plr.pos_x && \
									game->enemy[i].pos_y == game->plr.pos_y)
			game->data[DATA_EXIT] = -1;
		i += 1;
	}
}

void	set_animation(t_game *game)
{
	game->anim_flag += 1;
	if (game->anim_flag == ANIM_SPEED)
	{
		game->anim_flag = 0;
		game->cllct_state = (game->cllct_state + 1) % CLLCT_ANIMATION;
		move_enemies(game);
	}
}
