/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:22:50 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 01:20:03 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*all;

	if (!init_struct(&all))
		exit (1);
	check_arg(argc, argv, all);
	parser(all);
	if (!start_mlx(all->win))
		err_shutdown(all, "MiniLibX error", strerror(errno));
	render_frame(all->game, all->win);
	mlx_key_hook(all->win->win, &handle_keys, all);
	mlx_hook(all->win->win, 17, (1L << 17), &shutdown, all);
	mlx_loop(all->win->mlx);
	return (0);
}
