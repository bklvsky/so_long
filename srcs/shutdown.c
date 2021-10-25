/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:08:09 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/26 00:23:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_struct(t_data *all)
{
	free(all->win->img);
	free(all->win);
	ft_free_charmtrx(all->game->map);
	free(all->game->data);
	free(all->game->enemy);
	free(all->game);
//	free(all);
}

void	clear_img_buf(void *mlx, t_img *img_buf, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (img_buf[i].img)
			mlx_destroy_image(mlx, img_buf[i].img);
		i += 1;
	}
}

int		stop_game(t_data *all)
{
	clear_img_buf(all->win->mlx, all->win->env, 4);
	clear_img_buf(all->win->mlx, all->win->enemy, ENEMY_ANIMATION);
	clear_img_buf(all->win->mlx, all->win->cllct, CLLCT_ANIMATION);
	clear_img_buf(all->win->mlx, all->win->plr, 4);
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
