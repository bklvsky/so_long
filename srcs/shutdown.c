/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:08:09 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 17:47:10 by dselmy           ###   ########.fr       */
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

int	shutdown(t_data *all)
{
	clear_game(all->win);
	free_struct(all);
	exit(0);
	return (0);
}
