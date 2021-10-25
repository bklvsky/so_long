/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:22:50 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/25 02:54:11 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*in bonus this func goes in loop hook;
	animation will done this way: 
		put_enemy blablabla
		put cllct is already good
		separate functions that will change index of state
		check for collisions with enemies in render game*/


void	render_game(t_game *game, t_win *win)
{
	mlx_do_sync(win->mlx);
	get_start_pos(win, game->plr);
	put_map(win, game);
	put_player(win, game->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
	if (game->data[DATA_EXIT] == 0)
		printf("CONGRATULATIONS, \
		YOU WON WITH THE FINAL SCORE OF %d MOVES\n", game->moves);
/*	else if (game->data[DATA_EXIT] == -1)
		printf("u fucked up with enemies lol\n");
	*/
}

int	main(int argc, char **argv)
{
	t_data	*all;

	if (!init_struct(&all))
		exit (1);
	check_arg(argc, argv, all);
	parser(all);
	if (!start_win(all->win))
		shutdown(all, "MiniLibX error", strerror(errno));
	// in_bonus -> start animation
	render_game(all->game, all->win);
	mlx_key_hook(all->win->win, &handle_keys, all);
	mlx_hook(all->win->win, 17, (1L<<17), &stop_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}
