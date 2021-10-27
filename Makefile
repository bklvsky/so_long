# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2021/10/27 03:34:48 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR =			./srcs/
SRCS_DIR_BONUS =	./srcs_bonus/
INC_DIR =			./includes/
MLX_DIR =			./minilibx-linux/
LIBFT_DIR =			./libft/
BONUS_DIR =			./so_long_bonus/
NO_BONUS_DIR =		./so_long/

SRCS_COM = 		$(filter-out $(SRCS_NO_COM), \
				$(shell find $(SRCS_DIR) -maxdepth 1 -name "*.c"))
SRCS_NO_COM =	$(SRCS_DIR)so_long.c
SRCS_BONUS =	$(shell find $(SRCS_DIR_BONUS) -maxdepth 1 -name "*.c")

MLX_FLAGS =		-lXext -lX11 -lm -lbsd
CFLAGS =		-Wall -Werror -Wextra
BONUS_FLAGS =	-D BONUS=1

ifdef WITH_BONUS
SRCS = $(SRCS_COM) $(SRCS_BONUS)
FLAGS = $(BONUS_FLAGS) $(CFLAGS)
INC = $(INC_DIR)so_long.h $(INC_DIR)so_long_bonus.h
NAME_DIR = $(BONUS_DIR)
else
SRCS = $(SRCS_COM) $(SRCS_NO_COM)
FLAGS = $(CFLAGS)
INC = $(INC_DIR)so_long.h
NAME_DIR = $(NO_BONUS_DIR)
endif

NAME =	$(NAME_DIR)so_long

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME_DIR) $(NAME) $(INC)

$(NAME_DIR):
		mkdir $(NAME_DIR)

$(NAME): $(OBJ) $(INC)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		gcc -o $(NAME) $(FLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)libft.a \
		$(MLX_DIR)libmlx_Linux.a $(MLX_FLAGS)
		
%.o:	%.c $(INC)
		gcc -c $(FLAGS) -I$(INC_DIR) $< -o $@

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(MLX_DIR)
		rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		rm -rf $(BONUS_DIR) $(NO_BONUS_DIR)
		
re: fclean all

bonus:
			$(MAKE) WITH_BONUS=1

.PHONY: all clean fclean re
