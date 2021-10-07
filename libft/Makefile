NAME = libft.a

SRCS =  $(addprefix $(SRCS_DIR), $(shell find $(SRCS_DIR) -maxdepth 1 -name "*.c"))

OBJS = $(SRCS:.c=.o)

INCLUDES = ./

HEADER = libft.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJS): %.o: %.c
		gcc -c $(FLAGS) $< -I$(INCLUDES) -o $@

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
