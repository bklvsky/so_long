/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:58:03 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 01:32:23 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./so_long.h"

# define ANIM_SPEED 700
# define ENEMY_ANIM_SPEED 1000
# define EN_MOVES_FOR_SQUARE 2

int	get_animation_tex(t_win *win);

void    move_enemies(t_game *game);

#endif