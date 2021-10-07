/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:41:23 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/08 01:46:08 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		start_win(t_win *win)
{
	int		x_screen;
	int		y_screen;

	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	mlx_get_screen_size(win->mlx, &x_screen, &y_screen);
	printf("x_screen = %d, y_screen = %d\n x_win = %d, y_win = %d,", x_screen, y_screen, win->x_win, win->y_win);
	if (win->x_win > x_screen || win->y_win > y_screen)
	{
		printf("fucked up resolution\n");
		return (0);
	}
	win->img = mlx_new_image(win->mlx, win->x_win, win->y_win);
	if (!win->img)
	{
		printf("no image for you\n");
		return (0);
	}
	printf("got an image\n");
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->en));
	if (!win->addr)
	{
		mlx_destroy_image(win->mlx, win->img);
		return (0);
	}
	win->win = mlx_new_window(win->mlx, win->x_win, win->y_win, "So_long");
	if (!win->win)
	{
		mlx_destroy_image(win->mlx, win->img);
		return (0);
	}
	return (1);
/*	WINDOW SIZE MANAGEMENT -- TO DO LATER	
	if (win->y_win > y_screen)
		win->y_win = y_screen;
	if (win->x_win > x_screen)
		win->x_win = x_screen;*/
//	win->img = mlx_new_image(win->mlx);
}

void	get_win_res(t_win *win, char **map)
{
	printf("in getwinres\n");
	win->x_win = ft_strlen(*map) * SCALE;
	win->y_win = ft_charmtrx_len(map) * SCALE;
	printf("ft_strlen = %ld, ft_mtrx_len = %ld\n", ft_strlen(*map), ft_charmtrx_len(map));
	printf("in get win res x_win = %d, y_win = %d\n", win->x_win, win->y_win);
}

void	my_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;
	
	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_square(t_win *win, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCALE)
	{
		j = 0;
		while(j < SCALE)
		{
			my_pixel_put(win, x + j, y + i, color);
			j += 1;
		}
		i += 1;
	}
}



void	put_map(t_win *win, t_game *game, char **map)
{
	int		y;
	int		x;

	y = -1;
	printf("in put map\n");
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
			{
				put_square(win, x * SCALE, y * SCALE, WALL_COLOR);
				continue ;
			}
			put_square(win, x * SCALE, y * SCALE, FLOOR_COLOR);
			if (map[y][x] == '0')
				continue ;
			if (map[y][x] == 'C')
				put_square(win, x * SCALE, y * SCALE, CLLCT_COLOR);
			else if (map[y][x] == 'E' && game->cllct == 0)
				put_square(win, x * SCALE, y * SCALE, EXIT_COLOR_ON);
			else if (map[y][x] == 'E' && game->cllct != 0)
				put_square(win, x * SCALE, y * SCALE, EXIT_COLOR_OFF);
		}
	}
}

void	render_game(char **map, t_game *game, t_win *win)
{
	put_map(win, game, map);
	put_square(win, game->plr_x * SCALE, game->plr_y * SCALE, PLR_COLOR);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	if (game->exit == 0)
	{
		printf("CONGRATULATIONS, YOU WON WITH THE SCORE OF %d\n", game->moves);
	}
}

/*void	collect_treasure(char *treasure, t_game *game)
{
	*treasure = '0';
	game->cllct -= 1;
}*/

void	move_player(char **map, t_game *game)
{
	game->moves += 1;
	if (map[game->plr_y][game->plr_x] == 'C')
	{
		map[game->plr_y][game->plr_x] = '0';
		game->cllct -= 1;
		printf("coolectibles left: %d\n", game->cllct);
	}
	if (map[game->plr_y][game->plr_x] == 'E' && game->cllct == 0)
		game->exit = 0;
	printf("MOVES: %d\n", game->moves);
}

void	plr_up(char **map, t_game *game)
{
	if (map[game->plr_y - 1][game->plr_x] == '1')
		return ;
	game->plr_y -= 1;
	move_player(map, game);
}

void	plr_down(char **map, t_game *game)
{
	if (map[game->plr_y + 1][game->plr_x] == '1')
		return ;
	game->plr_y += 1;
	move_player(map, game);
}

void	plr_left(char **map, t_game *game)
{
	if (map[game->plr_y][game->plr_x - 1] == '1')
		return ;
	game->plr_x -= 1;
	move_player(map, game);
}

void	plr_right(char **map, t_game *game)
{
	if (map[game->plr_y][game->plr_x + 1] == '1')
		return ;
	game->plr_x += 1;
	move_player(map, game);
}

int		handle_keys(int key, t_data *all)
{
	if (key == 119)
		plr_up(all->map, all->game);
	else if (key == 115)
		plr_down(all->map, all->game);
	else if (key == 97)
		plr_left(all->map, all->game);
	else if (key == 100)
		plr_right(all->map, all->game);
	render_game(all->map, all->game, all->win);
	if (all->game->exit == 0)
		stop_game(all);
	return (0);
}

void	launch_game(t_data *all)
{
	get_win_res(all->win, all->map);
	if (!start_win(all->win))
		shutdown(all, NULL, "MiniLibX error");
	render_game(all->map, all->game, all->win);
	mlx_key_hook(all->win->win, &handle_keys, all);
	mlx_hook(all->win->win, 17, (1L<<17), &stop_game, all);
	mlx_loop(all->win->mlx);
}