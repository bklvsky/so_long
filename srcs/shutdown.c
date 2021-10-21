/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:08:09 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/21 03:51:49 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_struct(t_data *all)
{
//	printf("in free_struct\n");
/*	free(all->win->floor_tex);
	free(all->win->wall_tex);
	free(all->win->cllct_tex);
	free(all->win->plr_tex);*/
	free(all->win->tex_table);
	free(all->win->img);
//	free(all->win->img);
	free(all->win);
	free(all->game);
	ft_free_charmtrx(all->map);
	free(all);
}

int		stop_game(t_data *all)
{
	int		i;

	i = 0;
	while (i <= 4 && all->win->tex_table[i].img)
	{
		mlx_destroy_image(all->win->mlx, all->win->tex_table[i].img);
		i += 1;
	}
	mlx_destroy_image(all->win->mlx, all->win->img->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
//	mlx_destroy_display(all->win->mlx);
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