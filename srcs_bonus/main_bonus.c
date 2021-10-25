/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:26:36 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/26 02:34:22 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

//handle_keys is not common btw

void	set_animation(t_game *game)
{
//	printf("game->anim_flag = %d\n", game->anim_flag);
	game->anim_flag += 1;
	if (game->anim_flag == ANIM_SPEED)
	{
		game->anim_flag = 0;
		game->cllct_state = (game->cllct_state + 1) % CLLCT_ANIMATION;
		move_enemies(game);
	}
}

/*for now only in small win*/

//void	put_enemy_img(t_win *win, t_)

void	put_enemies(t_win *win, t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemy_num)
	{
		if (game->enemy[i].pos_y == game->plr.pos_y && \
									game->enemy[i].pos_x == game->plr.pos_y)
			game->data[DATA_EXIT] = -1;
		put_square(win->img, win->enemy[game->enemy[i].state], \
					game->enemy[i].win_x, game->enemy[i].win_y);
		i += 1;
	}
}

void	render_game(t_game *game, t_win *win)
{
	get_start_pos(win, game->plr);
	put_map(win, game);
	put_enemies(win, game);
	put_player(win, game->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
}

int		render_all(t_data *all)
{
//	printf("in render all game->anim_flag = %d\n", all->game->anim_flag);
	mlx_do_sync(all->win->mlx);
	set_animation(all->game);
	if (all->game->anim_flag == 0)
		render_game(all->game, all->win);
	if (all->game->data[DATA_EXIT] <= 0)
	{
		if (all->game->data[DATA_EXIT] == 0)
			printf("CONGRATULATIONS, YOU WON WITH THE FINAL SCORE OF %d MOVES\n", all->game->moves);
		else
			printf("YOU LOST! MIND ENEMIES NEXT TIME\n");
		stop_game(all);
	}
	return (0);
}

int     main(int argc, char **argv)
{
	t_data	*all;

//	printf("ENEMY_ANIM = %d\n", ENEMY_ANIMATION);
	if (!init_struct(&all))
		exit (1);
	check_arg(argc, argv, all);
	parser(all);
	if (!start_win(all->win) || !get_animation_tex(all->win))
		shutdown(all, "MiniLibX error", strerror(errno));
	render_game(all->game, all->win);
	mlx_loop_hook(all->win->mlx, &render_all, all);
	mlx_hook(all->win->win, 2, (1L<<0), &handle_keys, all);
//	mlx_hook(all->win->win 3, (1L<<0), &)
	mlx_hook(all->win->win, 17, (1L<<17), &stop_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}