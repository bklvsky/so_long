/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:58:03 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/10 17:54:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./so_long.h"

# define ANIM_SPEED 300
# define EN_MOVES_FOR_SQUARE 2

int		render_all(t_data *all);

int		get_animation_tex(t_win *win);

void	set_animation(t_game *game);

int		print_moves(t_win *win, int moves);
void	put_enemies(t_win *win, t_game *game);

#endif
