/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:12:12 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/20 22:59:37 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_struct(t_data **all)
{
	*all = (t_data *)malloc(sizeof(t_data));
	if (!(*all))
		return (0);
	(*all)->win = (t_win *)ft_calloc(1, sizeof(t_win));
	if (!(*all)->win)
		return (0);
	(*all)->win->tex_table = (t_img *)ft_calloc(5, sizeof(t_img));
	(*all)->win->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!(*all)->win->tex_table)
		return (0);
	(*all)->game = (t_game *)ft_calloc(1, sizeof(t_game));
/*	printf("plr_x %d\n", (*all)->game->plr_x);
	printf("plr_y %d\n", (*all)->game->plr_y);
	printf("cllct_num %d\n", (*all)->game->cllct_num);
	printf(" moves %d\n", (*all)->game->moves);*/
	if (!(*all)->win || !(*all)->game)
	{
		free(*all);
		return (0);
	}
	(*all)->map = NULL; 
	(*all)->map_fd = -1;
	return (1);
}