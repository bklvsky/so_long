/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:26:36 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 01:55:36 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*all;

	if (!init_struct(&all))
		exit (1);
	check_arg(argc, argv, all);
	parser(all);
	if (!start_mlx(all->win) || !get_animation_tex(all->win))
		err_shutdown(all, "MiniLibX error", strerror(errno));
	render_frame(all->game, all->win);
	mlx_loop_hook(all->win->mlx, &render_all, all);
	mlx_hook(all->win->win, 2, (1L << 0), &handle_keys, all);
	mlx_hook(all->win->win, 17, (1L << 17), &shutdown, all);
	mlx_loop(all->win->mlx);
	return (0);
}
