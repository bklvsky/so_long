/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:42:52 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/26 02:42:08 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_data *all, char **map)
{
	int		y;
	int		map_x;

	y = 0;
	skip_newlines(map, &y);
	map_x = check_closed_line(map[y]);
	if (map_x < 0)
		shutdown(all, NULL, "The map is not closed");
	while (map[++y])
	{
		if (map[y][0] == '\0')
		{
			if (check_closed_line(map[y - 1]) < 0)
				shutdown(all, NULL, "The map is not closed");
			break ;
		}
		check_one_line(all, map[y], map_x);
	}
	skip_newlines(map, &y);
	if (map[y] != NULL)
		shutdown(all, NULL, "Symbols after the map");
}

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

int	check_game_data(int *data)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (!data[i])
			return (-1);
		i += 1;
	}
	return (0);
}

void	parser(t_data *all)
{
	all->game->map = read_conf(all->map_fd);
	if (!all->game->map)
		shutdown(all, NULL, strerror(errno));
	check_map(all, all->game->map);
	all->game->map = ft_charmtrx_trim(all->game->map);
	all->game->enemy = (t_enemy *)ft_calloc(all->game->enemy_num, \
															sizeof(t_enemy));
	if (!all->game->map || (!all->game->enemy && all->game->enemy_num))
		shutdown(all, NULL, strerror(errno));
	parse_map(all->game);
	if (check_game_data(all->game->data) < 0)
		shutdown(all, NULL, "Game elements are missing in the map");
	if (all->game->data[DATA_PLR] > 1)
		shutdown(all, NULL, "More than one player encountered in the map");
	get_map_res(all->win, all->game->map);
}
