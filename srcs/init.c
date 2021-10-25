/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:12:12 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/25 03:11:34 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//UTILS

int	init_struct(t_data **all)
{
	*all = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!(*all))
		return (0);
	(*all)->win = (t_win *)ft_calloc(1, sizeof(t_win));
	(*all)->game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!(*all)->win || !(*all)->game)
		return (0);
	(*all)->game->data = (int *)ft_calloc(3, sizeof(int));
	(*all)->win->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!(*all)->game->data || !(*all)->win->img)
		return (0);
//	(*all)->win->texs = (t_img *)ft_calloc(8, sizeof(t_img));
	return (1);
}
