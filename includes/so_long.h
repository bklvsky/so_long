/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:03:01 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/08 01:33:46 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define SCALE 32

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*buf;
	void		*addr;
	int			line_len;
	int			bpp;
	int			en;
	int			x_win;
	int			y_win;
}				t_win;

typedef struct s_game
{
//	char		**map;
	int			plr;
	int			exit;
	int			cllct;
	int			plr_x;
	int			plr_y;
	int			moves;
}				t_game;

typedef struct s_data
{
	t_win		*win;
	int			map_fd;
	char		**map;
	t_game		*game;
}				t_data;

int	init_struct(t_data **all);

void    parser(t_data *all);

void	skip_newlines(char **map, int *y);
int		check_sym_map(char *line);
int		check_closed_line(char *line);
void	check_one_line(t_data *all, char *line, int map_x);
void	get_game_data(t_game *game, int c, int x, int y);

void	launch_game(t_data *all);

void	shutdown(t_data *all, char *err_ident, char *err_message);
int		stop_game(t_data *all);

# define WALL_COLOR 0x00FAD564
# define FLOOR_COLOR 0x00FFFEB3
# define CLLCT_COLOR 0x006FCB9F
# define PLR_COLOR 0x00FB2E01
# define EXIT_COLOR_ON 0x00FFBEE6
# define EXIT_COLOR_OFF 0x00595959

#endif