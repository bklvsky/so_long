/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:37:14 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/03 16:39:44 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	clear_game(t_win *win)
{
	clear_img_buf(win->mlx, win->env, 4);
	clear_img_buf(win->mlx, win->enemy, ENEMY_ANIMATION);
	clear_img_buf(win->mlx, win->cllct, CLLCT_ANIMATION);
	clear_img_buf(win->mlx, win->plr, 4);
	if (win->img->img)
		mlx_destroy_image(win->mlx, win->img->img);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
}
