/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:42:52 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/07 21:02:23 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



/*
void	*expand_arr(void *arr, unsigned size)
{
	void	*new;

	new = (void *)malloc(size);
	if (new)
		ft_memccpy(new, arr, 0, size);
	free(arr);
	return (new);
}
*/

void	read_conf(t_data *all)
{
	int		gnl_flag;
	int		y;

	y = 0;
	all->map = (char **)ft_calloc(2, sizeof(char *));
	gnl_flag = get_next_line(all->map_fd, all->map);
//	all->map[1] = NULL;
	while (gnl_flag)
	{
		if (gnl_flag == -1)
			shutdown(all, NULL, strerror(errno));
//		printf("y = %d %s\n", y, all->map[y]);
		y += 1;
		all->map = ft_realloc_charmtrx(all->map, y + 1);
		gnl_flag = get_next_line(all->map_fd, &all->map[y]);
	/*	if (ft_strlen(all->map[y]) != all->map_x)
			shutdown(all, NULL, "The all->map is not rectangular");*/
	}
	close(all->map_fd);
//	printf("y = %d\n", y);
/*	y = 0;
	while (all->map[y])
	{
		printf("%d %s\n", y, all->map[y]);
		y += 1;
	}*/
//	free_arr(all->map);
}

void	check_map(t_data *all)
{
	int		y;
	int		map_x;

	y = 0;
	skip_newlines(all->map, &y);
	map_x = check_closed_line(all->map[y]);
	if (map_x < 0)
		shutdown(all, NULL, "The map is not closed");
	while (all->map[++y])
	{
		if (all->map[y][0] == '\0')
		{
			if (check_closed_line(all->map[y - 1]) < 0)
				shutdown(all, NULL, "The map is not closed");
			break ;
		}
		check_one_line(all, all->map[y], map_x);
	}
	skip_newlines(all->map, &y);
	if (all->map[y] != NULL)
		shutdown(all, NULL, "Symbols after the map");
/*	while (all->map[y])
	{
		x = -1;
		if (ft_strlen(all->map[y]) != map_x)
			shutdown(all, NULL, "Map is not rectangular");
		while (all->map[y][++x])
		{
			if (map[y][x] == '1' || map[y][x] == '0')
				continue ;
			else if (ft_strchr("CEP", map[y][x]))
				get_game_data(all->game, map[y][x], x, y);
			else
				shutdown(all, NULL, "Unknown symbol in the map");
		}
		y += 1;
	}*/
}

void	parse_map(t_game *game, char **map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			while (map[y][x] == '1' || map[y][x] == '0')
				x += 1;
			if (!map[y][x])
				break ;
			get_game_data(game, map[y][x], x, y);
			x += 1;
		}
		y += 1;
	}
}

int	check_game_data(t_game *game)
{
	if (game->cllct == 0 || game->exit == 0 || game->plr != 1)
		return (-1);
	return (0);
}

void	parser(t_data *all)
{
	read_conf(all);
	check_map(all);
	all->map = ft_charmtrx_trim(all->map);
	if (!all->map)
		shutdown(all, NULL, strerror(errno));
/*	int y = 0;
	while (all->map[y])
	{
		printf("%d %s\n", y, all->map[y]);
		y += 1;
	}*/
	parse_map(all->game, all->map);
	if (check_game_data(all->game) < 0)
	{
		if (all->game->plr > 1)
			shutdown(all, NULL, "More than one player encountered in the map");
		shutdown(all, NULL, "Game elements are missing in the map");
	}
}