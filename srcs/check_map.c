/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:05:54 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 17:31:29 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	clear_characters(char *c)
{
	if (*c == 'H' || *c == 'V' || *c == 'P')
		*c = '0';
}

void	parse_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			while (game->map[y][x] == '1' || game->map[y][x] == '0')
				x += 1;
			if (!game->map[y][x])
				break ;
			get_game_data(game, game->map[y][x], x, y);
			clear_characters(&(game->map[y][x]));
			x += 1;
		}
		y += 1;
	}
}

void	check_map(t_data *all, char **map)
{
	int		y;
	int		map_x;

	y = 0;
	skip_newlines(map, &y);
	map_x = check_closed_line(map[y]);
	if (map_x < 0)
		err_shutdown(all, NULL, "The map is not closed");
	while (map[++y])
	{
		if (map[y][0] == '\0')
		{
			if (check_closed_line(map[y - 1]) < 0)
				err_shutdown(all, NULL, "The map is not closed");
			break ;
		}
		check_one_line(all, map[y], map_x);
	}
	skip_newlines(map, &y);
	if (map[y] != NULL)
		err_shutdown(all, NULL, "Symbols after the map");
}
