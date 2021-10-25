# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2021/10/26 02:48:27 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

SRCS_DIR =			./srcs/
SRCS_DIR_BONUS =	./srcs_bonus/
INC_DIR =			./includes/
MLX_DIR =			./minilibx-linux/
LIBFT_DIR =			./libft/

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
else
SRCS = $(SRCS_COM) $(SRCS_NO_COM)
FLAGS = $(CFLAGS)
INC = $(INC_DIR)so_long.h
endif

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME) $(INC)

$(NAME): $(OBJ) $(INC)
			@make -C $(LIBFT_DIR)
			@make -C $(MLX_DIR)
			gcc -o $(NAME) $(FLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)libft.a \
			$(MLX_DIR)libmlx_Linux.a $(MLX_FLAGS)
		
%.o:	%.c $(INC)
			gcc -c $(FLAGS) -I$(INC_DIR) $< -o $@

clean:
			@make clean -C $(LIBFT_DIR)
			rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
			@make fclean -C $(LIBFT_DIR)
			rm -f $(NAME)
		
re: fclean all

bonus:
			$(MAKE) WITH_BONUS=1

try:
	@echo "SRCS:"
	@echo $(SRCS)
	@echo "SRC_COM:"
	@echo $(SRCS_COM)
	@echo "SRCS_BONUS:"
	@echo $(SRCS_BONUS)

.PHONY: all clean fclean re
