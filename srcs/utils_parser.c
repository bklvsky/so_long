/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:54:06 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/07 20:56:42 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	skip_newlines(char **map, int *y)
{
	while (map[*y])
	{
		if (map[*y][0] != '\0')
			break ;
		*y += 1;
	}
}

int		check_sym_map(char *line)
{
	int		x;

	x = 0;
	while (ft_strchr("01PEC", line[x]) && line[x])
	{
		
	}
	if (line[x] != '\0')
		return (-1);
	return (0);
}

int		check_closed_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] == '1')
		i += 1;
	if (line[i] != '\0')
		return (-1);
	return (i);
}

void	check_one_line(t_data *all, char *line, int map_x)
{
	int		i;

	i = 0;
	while (ft_strchr("10ECP", line[i]) && line[i])
		i += 1;
//	printf("in check one line i = %d\n", i);
	if (line[i] != '\0')
		shutdown(all, NULL, "Unknown symbol in the map");
	if (i != map_x)
		shutdown(all, NULL, "The map is not rectangular");
	if (line[0] != '1' || line[i - 1] != '1')
		shutdown(all, NULL, "The map is not closed");
}


void	get_game_data(t_game *game, int c, int x, int y)
{
	if (c == 'E')
		game->exit += 1;
	else if (c == 'C')
		game->cllct += 1;
	else
	{
		game->plr_x = x;
		game->plr_y = y;
		game->plr += 1;
	}
}