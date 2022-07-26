/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:32:39 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/05 23:54:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keys(int key, t_data *all)
{
	if (key == KEY_W)
		plr_up(all->game);
	else if (key == KEY_S)
		plr_down(all->game);
	else if (key == KEY_A)
		plr_left(all->game);
	else if (key == KEY_D)
		plr_right(all->game);
	else if (key == ESC)
		shutdown(all);
	else
		return (0);
	render_frame(all->game, all->win);
	if (all->game->data[DATA_EXIT] <= 0)
		shutdown(all);
	return (0);
}
