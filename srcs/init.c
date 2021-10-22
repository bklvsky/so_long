/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:12:12 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/22 22:20:14 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_struct(t_data **all)
{
	*all = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!(*all))
		return (0);
	(*all)->win = (t_win *)ft_calloc(1, sizeof(t_win));
	if (!(*all)->win)
		return (0);
	(*all)->win->texs = (t_img *)ft_calloc(8, sizeof(t_img));
	(*all)->win->img = (t_img *)ft_calloc(1, sizeof(t_img));
	(*all)->game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!(*all)->win->img || !(*all)->win->texs || !(*all)->game)
	{
		free(*all);
		return (0);
	}
	return (1);
}
