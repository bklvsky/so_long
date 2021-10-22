/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:08:09 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/22 22:20:34 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_struct(t_data *all)
{
	free(all->win->img);
	free(all->win->texs);
	free(all->win);
	free(all->game);
	ft_free_charmtrx(all->map);
	free(all);
}

int		stop_game(t_data *all)
{
	int		i;

	i = 0;
	while (i <= 7 && all->win->texs[i].img)
	{
		mlx_destroy_image(all->win->mlx, all->win->texs[i].img);
		i += 1;
	}
	mlx_destroy_image(all->win->mlx, all->win->img->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	shutdown(all, NULL, NULL);
	return (0);
}

void	shutdown(t_data *all, char *err_ident, char *err_message)
{
	if (err_message)
	{
		ft_putendl_fd("Error", 2);
		if (err_ident)
			{
				ft_putstr_fd(err_ident, 2);
				ft_putstr_fd(": ", 2);
			}
		ft_putendl_fd(err_message, 2);
	}
	free_struct(all);
	exit(0);
}
