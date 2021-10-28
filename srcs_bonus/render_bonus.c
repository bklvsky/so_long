/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:14:22 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 05:39:09 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	render_frame(t_game *game, t_win *win)
{
	get_start_pos(win, game->plr);
	put_map(win, game);
	put_enemies(win, game);
	put_player(win, game->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
	if (!print_moves(win, game->moves))
		return (0);
	if (game->data[DATA_EXIT] == 0)
		printf("CONGRATULATIONS, \
YOU WON WITH THE FINAL SCORE OF %d MOVES\n", game->moves);
	else if (game->data[DATA_EXIT] == -1)
		printf("YOU LOST! MIND ENEMIES NEXT TIME\n");
	return (1);
}

int	render_all(t_data *all)
{
	mlx_do_sync(all->win->mlx);
	set_animation(all->game);
	if (all->game->anim_flag == 0)
		if (!render_frame(all->game, all->win))
			err_shutdown(all, NULL, strerror(errno));
	if (all->game->data[DATA_EXIT] <= 0)
		shutdown(all);
	return (0);
}
