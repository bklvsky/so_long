/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:08:09 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 01:20:22 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_struct(t_data *all)
{
	free(all->win->img);
	free(all->win->cllct);
	free(all->win->enemy);
	free(all->win);
	ft_free_charmtrx(all->game->map);
	free(all->game->data);
	free(all->game->enemy);
	free(all->game);
	free(all);
}

static void	clear_img_buf(void *mlx, t_img *img_buf, int size)
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

void	clear_game(t_win *win)
{
	clear_img_buf(win->mlx, win->env, 4);
	clear_img_buf(win->mlx, win->enemy, ENEMY_ANIMATION);
	clear_img_buf(win->mlx, win->cllct, CLLCT_ANIMATION);
	clear_img_buf(win->mlx, win->plr, 4);
	if (win->img->img)
		mlx_destroy_image(win->mlx, win->img->img);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
}

int	shutdown(t_data *all)
{
	clear_game(all->win);
	free_struct(all);
	exit(0);
	return (0);
}
