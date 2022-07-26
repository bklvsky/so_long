/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:13:01 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/05 23:53:45 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_frame(t_game *game, t_win *win)
{
	mlx_do_sync(win->mlx);
	get_start_pos(win, game->plr);
	put_map(win, game);
	put_player(win, game->plr);
	printf("MOVES: %d\n", game->moves);
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
	if (game->data[DATA_EXIT] == 0)
		printf("CONGRATULATIONS, \
YOU WON WITH THE FINAL SCORE OF %d MOVES\n", game->moves);
	return (0);
}
