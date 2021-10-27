/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:26:36 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/27 03:05:21 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	set_animation(t_game *game)
{
	game->anim_flag += 1;
	if (game->anim_flag == ANIM_SPEED)
	{
		game->anim_flag = 0;
		game->cllct_state = (game->cllct_state + 1) % CLLCT_ANIMATION;
		move_enemies(game);
	}
}

int		is_on_screen(t_win *win, t_enemy enemy)
{
	return (enemy.win_x > win->start_draw_x * SCALE && \
	enemy.win_x < (win->start_draw_x * SCALE) + win->img->width && \
	enemy.win_y > win->start_draw_y * SCALE && \
	enemy.win_y < (win->start_draw_y * SCALE) + win->img->height);
}

void	put_enemies(t_win *win, t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemy_num)
	{
		if (game->enemy[i].pos_y == game->plr.pos_y && \
									game->enemy[i].pos_x == game->plr.pos_x)
			game->data[DATA_EXIT] = -1;
		if (is_on_screen(win, game->enemy[i]))
			put_square(win->img, win->enemy[game->enemy[i].state], \
			(game->enemy[i].win_x - win->start_draw_x * SCALE), \
			game->enemy[i].win_y - win->start_draw_y * SCALE);
		i += 1;
	}
}

static int	print_moves(t_win *win, int moves)
{
	char	*str;
	char	*str_num;

	str_num = ft_itoa(moves);
	str = ft_strjoin("MOVES  ", str_num);
	if (!str_num || !str)
		return (0);
	mlx_string_put(win->mlx, win->win, 5, 20, 0, str);
	free(str);
	free(str_num);
	return (1);
}

void	render_game(t_game *game, t_win *win)
{
	get_start_pos(win, game->plr);
	put_map(win, game);
	put_enemies(win, game);
	put_player(win, game->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
	print_moves(win, game->moves);
}
int		render_all(t_data *all)
{
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

	if (!init_struct(&all))
		exit (1);
	check_arg(argc, argv, all);
	parser(all);
	if (!start_win(all->win) || !get_animation_tex(all->win))
		shutdown(all, "MiniLibX error", strerror(errno));
	render_game(all->game, all->win);
	mlx_loop_hook(all->win->mlx, &render_all, all);
	mlx_hook(all->win->win, 2, (1L<<0), &handle_keys, all);
	mlx_hook(all->win->win, 17, (1L<<17), &stop_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}