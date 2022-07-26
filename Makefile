# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2022/07/27 01:52:11 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_DIR =			./bin/
BIN_DIR_BONUS =		./bin_bonus/

NAME =				$(BIN_DIR)so_long
NAME_BONUS =		$(BIN_DIR_BONUS)so_long

INC_DIR =			./includes/
MLX_DIR =			./minilibx-linux/
LIBFT_DIR =			./libft/

SRCS =			./srcs/check_one_line.c \
				./srcs/clear_game.c \
				./srcs/main.c \
				./srcs/init.c \
				./srcs/render_frame.c \
				./srcs/check_map.c \
				./srcs/error_shutdown.c \
				./srcs/get_texture.c \
				./srcs/key_handle.c \
				./srcs/mlx_start.c \
				./srcs/mlx_utils.c \
				./srcs/parse_config.c \
				./srcs/render_utils.c \
				./srcs/shutdown.c \
				./srcs/utils_check.c \
				./srcs/utils_key_handle.c \
				./srcs/utils_parser.c
				
SRCS_BONUS =	./srcs/check_map.c \
				./srcs/error_shutdown.c \
				./srcs/get_texture.c \
				./srcs/key_handle.c \
				./srcs/mlx_start.c \
				./srcs/mlx_utils.c \
				./srcs/parse_config.c \
				./srcs/render_utils.c \
				./srcs/shutdown.c \
				./srcs/utils_check.c \
				./srcs/utils_key_handle.c \
				./srcs/utils_parser.c \
				./srcs_bonus/check_one_line_bonus.c \
				./srcs_bonus/clear_game_bonus.c \
				./srcs_bonus/get_animation_tex_bonus.c \
				./srcs_bonus/init_bonus.c \
				./srcs_bonus/main_bonus.c \
				./srcs_bonus/render_bonus.c \
				./srcs_bonus/render_utils_bonus.c \
				./srcs_bonus/set_animation_bonus.c

MLX_FLAGS =		-lXext -lX11 -lm -lbsd
CFLAGS =		-Wall -Werror -Wextra

ifdef MEME

CFLAGS += -D MEME=1

endif

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
DEP = $(SRCS:.c=.d)
DEP_BONUS = $(SRCS_BONUS:.c=.d)

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
		mkdir $(BIN_DIR)

$(NAME): $(OBJ)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		gcc -o $(NAME) $(CFLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)libft.a \
		$(MLX_DIR)libmlx_Linux.a $(MLX_FLAGS)
		cp $(NAME) ./

%.o:	%.c
		gcc -c $(CFLAGS) -I$(INC_DIR) $< -o $@ -MD

bonus: $(BIN_DIR_BONUS) $(NAME_BONUS)

$(BIN_DIR_BONUS):
		mkdir $(BIN_DIR_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		gcc -o $(NAME_BONUS) $(CFLAGS) -I$(INC_DIR) $(OBJ_BONUS) \
		$(LIBFT_DIR)libft.a $(MLX_DIR)libmlx_Linux.a $(MLX_FLAGS)
		cp $(NAME_BONUS) ./

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(MLX_DIR)
		rm -f $(OBJ) $(OBJ_BONUS) $(DEP) $(DEP_BONUS)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		rm -rf $(BIN_DIR) $(BIN_DIR_BONUS) ./so_long

re: fclean all

rebonus: fclean bonus

meme: 
	$(MAKE) bonus MEME=1


include $(wildcard $(DEP) $(DEP_BONUS))

.PHONY: all clean fclean re rebonus

