/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:58:03 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/26 02:33:07 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./so_long.h"

# define ENEMY_1_TEX_PATH "./textures_xpm/frog/enemy_1_tex.xpm"
# define ENEMY_2_TEX_PATH "./textures_xpm/frog/enemy_2_tex.xpm"
# define ENEMY_3_TEX_PATH "./textures_xpm/frog/enemy_3_tex.xpm"
# define ENEMY_4_TEX_PATH "./textures_xpm/frog/enemy_4_tex.xpm"
# define ENEMY_5_TEX_PATH "./textures_xpm/frog/enemy_5_tex.xpm"
# define ENEMY_6_TEX_PATH "./textures_xpm/frog/enemy_6_tex.xpm"

# define CLLCT_2_TEX_PATH "./textures_xpm/frog/collect_sprite_2_tex.xpm"
# define CLLCT_3_TEX_PATH "./textures_xpm/frog/collect_sprite_3_tex.xpm"

# define ANIM_SPEED 700
# define EN_MOVES_FOR_SQUARE 2

int	get_animation_tex(t_win *win);

void    move_enemies(t_game *game);

#endif