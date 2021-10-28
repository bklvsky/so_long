/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:42:34 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 17:55:30 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	(*all)->win->enemy = (t_img *)ft_calloc(ENEMY_ANIMATION, sizeof(t_img));
	(*all)->win->cllct = (t_img *)ft_calloc(CLLCT_ANIMATION, sizeof(t_img));
	if (!(*all)->game->data || !(*all)->win->img || !(*all)->win->cllct || \
													!(*all)->win->enemy)
		return (0);
	return (1);
}
