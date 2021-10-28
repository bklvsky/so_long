/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:54:06 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 01:22:28 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_res(t_win *win, char **map)
{
	win->map_x = (int)ft_strlen(*map) * SCALE;
	win->map_y = (int)ft_charmtrx_len(map) * SCALE;
}

void	skip_newlines(char **map, int *y)
{
	while (map[*y])
	{
		if (map[*y][0] != '\0')
			break ;
		*y += 1;
	}
}

int	check_closed_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] == '1')
		i += 1;
	if (line[i] != '\0')
		return (-1);
	return (i);
}

static void	get_enemy(t_enemy *enemy, int c, int x, int y)
{
	int		i;

	i = 0;
	while (enemy[i].init != 0)
		i += 1;
	if (c == 'H')
		enemy[i].dir_x = 1;
	else if (c == 'V')
		enemy[i].dir_y = 1;
	enemy[i].init = 1;
	enemy[i].pos_x = x;
	enemy[i].pos_y = y;
	enemy[i].win_x = x * SCALE;
	enemy[i].win_y = y * SCALE;
}

void	get_game_data(t_game *game, int c, int x, int y)
{
	if (c == 'E')
		game->data[DATA_EXIT] += 1;
	else if (c == 'C')
		game->data[DATA_CLLCT] += 1;
	else if (c == 'P')
	{
		game->plr.pos_x = x;
		game->plr.pos_y = y;
		game->data[DATA_PLR] += 1;
	}
	else if (c == 'H' || c == 'V')
		get_enemy(game->enemy, c, x, y);
}
