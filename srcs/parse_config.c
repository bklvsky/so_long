/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:42:52 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 23:36:18 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_game_data(int *data)
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

static char	**read_conf(int fd)
{
	char	**map;
	int		gnl_flag;
	int		y;

	y = 0;
	map = (char **)ft_calloc(2, sizeof(char *));
	gnl_flag = get_next_line(fd, map);
	while (gnl_flag)
	{
		if (gnl_flag == -1)
		{
			ft_free_charmtrx(map);
			return (NULL);
		}
		y += 1;
		map = ft_realloc_charmtrx(map, y + 1);
		gnl_flag = get_next_line(fd, &map[y]);
	}
	close(fd);
	return (map);
}

void	parser(t_data *all)
{
	all->game->map = read_conf(all->map_fd);
	if (!all->game->map)
		err_shutdown(all, NULL, strerror(errno));
	check_map(all, all->game->map);
	all->game->map = ft_charmtrx_trim(all->game->map);
	all->game->enemy = (t_enemy *)ft_calloc(all->game->enemy_num, \
															sizeof(t_enemy));
	if (!all->game->map || (!all->game->enemy && all->game->enemy_num))
		err_shutdown(all, NULL, strerror(errno));
	parse_map(all->game);
	if (check_game_data(all->game->data) < 0)
		err_shutdown(all, NULL, "Game elements are missing in the map");
	if (all->game->data[DATA_PLR] > 1)
		err_shutdown(all, NULL, "More than one player encountered in the map");
	get_map_res(all->win, all->game->map);
}
