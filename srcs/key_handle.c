/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:32:39 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/20 18:44:38 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(char **map, t_game *game)
{
	game->moves += 1;
	if (map[game->plr_y][game->plr_x] == 'C')
	{
		map[game->plr_y][game->plr_x] = '0';
		game->cllct -= 1;
		printf("colectibles left: %d\n", game->cllct);
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
	else
		return (0);
	render_game(all->map, all->game, all->win);
	if (all->game->exit == 0)
		stop_game(all);
	return (0);
}