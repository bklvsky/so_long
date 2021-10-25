/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:03:23 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/24 19:59:45 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_one_line(t_data *all, char *line, int map_x)
{
	int		i;

	i = 0;
	while (ft_strchr("10ECP", line[i]) && line[i])
		i += 1;
	if (line[i] != '\0')
		shutdown(all, NULL, "Unknown symbol in the map");
	if (i != map_x)
		shutdown(all, NULL, "The map is not rectangular");
	if (line[0] != '1' || line[i - 1] != '1')
		shutdown(all, NULL, "The map is not closed");
}