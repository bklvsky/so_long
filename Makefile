# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2021/10/22 19:30:54 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = ./srcs/

INC_DIR = ./includes/

MLX_DIR = ./minilibx-linux/

LIBFT_DIR = ./libft/

SRCS = $(shell find $(SRCS_DIR) -maxdepth 1 -name "*.c")

OBJ = $(SRCS:.c=.o)

MLX_FLAGS = -lXext -lX11 -lm -lbsd

FLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(INC_DIR)so_long.h
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		gcc -o $(NAME) $(FLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)libft.a $(MLX_DIR)libmlx_Linux.a\
		$(MLX_FLAGS)
		
%.o:	%.c $(INC_DIR)so_long.h
		gcc -c $(FLAGS) -I$(INC_DIR) $< -o $@

clean:
		@make clean -C $(LIBFT_DIR)
		rm -f $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
