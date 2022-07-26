/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:54:18 by dselmy            #+#    #+#             */
/*   Updated: 2022/07/27 01:37:46 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_file_format(char *file_name, char *format)
{
	int		form_len;
	int		file_name_len;

	form_len = ft_strlen(format);
	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(file_name + file_name_len - form_len, \
												format, form_len + 1) != 0)
		return (0);
	return (1);
}

void	check_arg(int argc, char **argv, t_data *all)
{
	if (argc != 2)
		err_shutdown(all, NULL, "Usage: ./so_long file_name");
	if (!(check_file_format(argv[1], ".ber")))
		err_shutdown(all, NULL, "The map in *.ber format is required");
	all->map_fd = open(argv[1], O_RDONLY);
	if (all->map_fd < 0)
		err_shutdown(all, argv[1], strerror(errno));
}
