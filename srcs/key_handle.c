/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:32:39 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 02:33:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keys(int key, t_data *all)
{
	int		res;

	if (key == KEY_W)
		res = plr_up(all->game);
	else if (key == KEY_S)
		res = plr_down(all->game);
	else if (key == KEY_A)
		res = plr_left(all->game);
	else if (key == KEY_D)
		res = plr_right(all->game);
	else if (key == ESC)
		shutdown(all);
	else
		return (0);
	if (res)
		all->game->move_flag = 1;
	render_frame(all->game, all->win);
	if (all->game->data[DATA_EXIT] <= 0)
		shutdown(all);
	return (0);
}
