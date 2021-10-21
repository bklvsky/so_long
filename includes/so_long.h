/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:03:01 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/21 03:09:28 by dselmy           ###   ########.fr       */
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

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			line_len;
	int			bpp;
	int			en;
	int			height;
	int			width;
}				t_img;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	t_img		*img;
//	void		*buf;
//	int			x_win;
//	int			y_win;
	t_img		*tex_table;
	int			start_draw_x;
	int			start_draw_y;
	int			map_x;
	int			map_y;
	int			flag_screen_x;
	int			flag_screen_y;
/*	t_img		*floor_tex;
	t_img		*wall_tex;
	t_img		*cllct_img;
	t_img		*plr_tex;
	t_img		*exit_img;*/
}				t_win;

# define FLOOR_TEX 0
# define WALL_TEX 1
# define CLLCT_TEX 2
# define PLR_TEX 3
# define EXIT_TEX 4

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
void	render_game(char **map, t_game *game, t_win *win);
void	put_map(t_win *win, char **map);

void	my_pixel_put(t_img *img, int x, int y, int color);
void	put_square(t_img *img, t_img tex, int x, int y);

int		handle_keys(int key, t_data *all);
void	plr_right(char **map, t_game *game);
void	plr_left(char **map, t_game *game);
void	plr_down(char **map, t_game *game);
void	plr_up(char **map, t_game *game);
void	move_player(char **map, t_game *game);

void	get_map_res(t_win *win, char **map);
int		start_win(t_win *win);
int		get_texture(t_win *win, t_img *tex_table);
int		get_tex_img(void *mlx, char *path, t_img *tex);
void	get_win_res(t_win *win);
//void	get_win_res(t_img *img, char **map);

void	shutdown(t_data *all, char *err_ident, char *err_message);
int		stop_game(t_data *all);
void	free_struct(t_data *all);

# define WALL_COLOR 0x00FAD564
# define FLOOR_COLOR 0x00FFFEB3
# define CLLCT_COLOR 0x006FCB9F
# define PLR_COLOR 0x00FB2E01
# define EXIT_COLOR_ON 0x00FFBEE6
# define EXIT_COLOR_OFF 0x00595959

# define FLOOR_TEX_PATH "textures_xpm/floor_tex.xpm"
# define WALL_TEX_PATH "./textures_xpm/wall_tex.xpm"
# define EXIT_TEX_PATH "./textures_xpm/exit_close_light_theme.xpm"
# define PLR_TEX_PATH "./textures_xpm/player_dark.xpm"
# define CLLCT_TEX_PATH "./textures_xpm/collect_sprite_16.xpm"

#endif