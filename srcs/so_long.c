/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:22:50 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/08 01:33:27 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_struct(t_data *all)
{
//	printf("in free_struct\n");
	free(all->win);
	free(all->game);
//	printf("freed winwin\n");
/*	free(all->win->mlx);
	printf("freed mlx\n");
	free(all->win->win);
	printf("freed win\n");
	free(all->win->img);
	printf("freed img\n");
	free(all->win->buf);
	printf("freed buf\n");
	free(all->win->addr);*/
	ft_free_charmtrx(all->map);
	free(all);
}

int		stop_game(t_data *all)
{
//	mlx_destroy_image(all->win->mlx, all->win->img);
//	mlx_destroy_window(all->win->mlx, all->win->win);
	mlx_destroy_image(all->win->mlx, all->win->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	shutdown(all, NULL, NULL);
	return (0);
}

void	shutdown(t_data *all, char *err_ident, char *err_message)
{
//	printf("in shutdown\n");
	if (err_ident)
		perror(err_ident);
	else
		ft_putendl_fd(err_message, 2);
	free_struct(all);
	exit(0);
}

int	check_file_format(char *file_name, char *format)
{
	int		form_len;
	int		file_name_len;

	form_len = ft_strlen(format);
	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(file_name + file_name_len - form_len, format, form_len + 1) != 0)
		return (0);
	return (1);
}

void	check_arg(int argc, char **argv, t_data *all)
{
	if (argc != 2)
		shutdown(all, NULL, "Usage: ./so_long file_name\n");
	all->map_fd = open(argv[1], O_RDONLY);
	if (!(check_file_format(argv[1], ".ber")))
		shutdown(all, NULL, "The map in *.ber format is required\n");
	else if (all->map_fd < 0)
		shutdown(all, argv[1], NULL);
}

int	main(int argc, char **argv)
{
	t_data	*all;
	
	if (!init_struct(&all))
	{
		return (1);
	}
	check_arg(argc, argv, all);
	parser(all);
	launch_game(all);
	shutdown(all, NULL, "All good, fuck off");
	return (0);
}