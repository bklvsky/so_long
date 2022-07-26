/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:03:01 by dselmy            #+#    #+#             */
/*   Updated: 2022/07/27 02:02:37 by dselmy           ###   ########.fr       */
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
# include <unistd.h>



# ifdef MEME

#  define SCALE 64
#  define FLOOR_TEX_PATH "./textures_xpm/meme/floor_tex.xpm"
#  define WALL_TEX_PATH "./textures_xpm/meme/wall_tex.xpm"
#  define EXIT_ON_TEX_PATH "./textures_xpm/meme/exit_open_tex.xpm"
#  define EXIT_OFF_TEX_PATH "./textures_xpm/meme/exit_close_tex.xpm"
 
#  define CLLCT_TEX_PATH "./textures_xpm/meme/collect_sprite_tex.xpm"
#  define CLLCT_2_TEX_PATH "./textures_xpm/meme/collect_sprite_2_tex.xpm"
#  define CLLCT_3_TEX_PATH "./textures_xpm/meme/collect_sprite_3_tex.xpm"
 
#  define PLR_UP_PATH "./textures_xpm/meme/plr_up_tex.xpm"
#  define PLR_DOWN_PATH "./textures_xpm/meme/plr_down_tex.xpm"
#  define PLR_LEFT_PATH "./textures_xpm/meme/plr_left_tex.xpm"
#  define PLR_RIGHT_PATH "./textures_xpm/meme/plr_right_tex.xpm"
 
#  define ENEMY_1_TEX_PATH "./textures_xpm/meme/enemy_1_tex.xpm"
#  define ENEMY_2_TEX_PATH "./textures_xpm/meme/enemy_2_tex.xpm"
#  define ENEMY_3_TEX_PATH "./textures_xpm/meme/enemy_3_tex.xpm"
#  define ENEMY_4_TEX_PATH "./textures_xpm/meme/enemy_4_tex.xpm"
#  define ENEMY_5_TEX_PATH "./textures_xpm/meme/enemy_5_tex.xpm"
#  define ENEMY_6_TEX_PATH "./textures_xpm/meme/enemy_6_tex.xpm"

# else

#  define SCALE 40
#  define FLOOR_TEX_PATH "./textures_xpm/frog/floor_tex.xpm"
#  define WALL_TEX_PATH "./textures_xpm/frog/wall_tex.xpm"
#  define EXIT_ON_TEX_PATH "./textures_xpm/frog/exit_open_tex.xpm"
#  define EXIT_OFF_TEX_PATH "./textures_xpm/frog/exit_close_tex.xpm"
 
#  define CLLCT_TEX_PATH "./textures_xpm/frog/collect_sprite_tex.xpm"
#  define CLLCT_2_TEX_PATH "./textures_xpm/frog/collect_sprite_2_tex.xpm"
#  define CLLCT_3_TEX_PATH "./textures_xpm/frog/collect_sprite_3_tex.xpm"
 
#  define PLR_UP_PATH "./textures_xpm/frog/plr_up_tex.xpm"
#  define PLR_DOWN_PATH "./textures_xpm/frog/plr_down_tex.xpm"
#  define PLR_LEFT_PATH "./textures_xpm/frog/plr_left_tex.xpm"
#  define PLR_RIGHT_PATH "./textures_xpm/frog/plr_right_tex.xpm"
 
#  define ENEMY_1_TEX_PATH "./textures_xpm/frog/enemy_1_tex.xpm"
#  define ENEMY_2_TEX_PATH "./textures_xpm/frog/enemy_2_tex.xpm"
#  define ENEMY_3_TEX_PATH "./textures_xpm/frog/enemy_3_tex.xpm"
#  define ENEMY_4_TEX_PATH "./textures_xpm/frog/enemy_4_tex.xpm"
#  define ENEMY_5_TEX_PATH "./textures_xpm/frog/enemy_5_tex.xpm"
#  define ENEMY_6_TEX_PATH "./textures_xpm/frog/enemy_6_tex.xpm"

# endif


# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define ESC 65307

# define FLOOR 0
# define WALL 1
# define EXIT_OFF 2
# define EXIT_ON 3

# define DATA_CLLCT 0
# define DATA_EXIT 1
# define DATA_PLR 2

# define PLR_UP 0
# define PLR_DOWN 1
# define PLR_LEFT 2
# define PLR_RIGHT 3

# define ENEMY_ANIMATION 6
# define CLLCT_ANIMATION 3

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
	t_img		env[4];
	t_img		*enemy;
	t_img		*cllct;
	t_img		plr[4];
	int			start_draw_x;
	int			start_draw_y;
	int			map_x;
	int			map_y;
	int			flag_screen_x;
	int			flag_screen_y;
}				t_win;

typedef struct s_enemy
{
	int			init;
	int			pos_x;
	int			pos_y;
	int			win_x;
	int			win_y;
	int			dir_x;
	int			dir_y;
	int			state;
}				t_enemy;

typedef struct s_plr
{
	int			pos_x;
	int			pos_y;
	int			dir;
}				t_plr;

typedef struct s_game
{
	char		**map;
	int			*data;
	t_plr		plr;
	int			anim_flag;
	int			cllct_state;
	t_enemy		*enemy;
	int			enemy_num;
	int			moves;
}				t_game;

typedef struct s_data
{
	int			map_fd;
	t_win		*win;
	t_game		*game;
}				t_data;

int		init_struct(t_data **all);

void	parser(t_data *all);

void	check_arg(int argc, char **argv, t_data *all);

void	check_one_line(t_data *all, char *line, int map_x);
void	check_map(t_data *all, char **map);
void	parse_map(t_game *game);

void	skip_newlines(char **map, int *y);
int		check_sym_map(char *line);
int		check_closed_line(char *line);
void	get_game_data(t_game *game, int c, int x, int y);

int		render_frame(t_game *game, t_win *win);

void	put_map(t_win *win, t_game *game);
void	put_player(t_win *win, t_plr plr);
void	get_start_pos(t_win *win, t_plr plr);

void	my_pixel_put(t_img *img, int x, int y, int color);
void	put_square(t_img *img, t_img tex, int x, int y);

int		handle_keys(int key, t_data *all);
int		plr_right(t_game *game);
int		plr_left(t_game *game);
int		plr_down(t_game *game);
int		plr_up(t_game *game);
void	move_player(t_game *game);

void	get_map_res(t_win *win, char **map);
int		start_mlx(t_win *win);
int		get_texture(t_win *win);
int		get_tex_img(void *mlx, char *path, t_img *tex);

void	err_shutdown(t_data *all, char *err_ident, char *err_message);
int		shutdown(t_data *all);
void	clear_img_buf(void *mlx, t_img *img_buf, int size);
void	clear_game(t_win *win);
void	free_struct(t_data *all);

#endif
