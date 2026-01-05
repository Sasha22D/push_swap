NAME = push_swap

SRCS = error_handler.c ft_split.c main.c push_cheapest.c push_commands.c push_swap.c \
       reverse_rotate_commands.c rotate_commands.c stack_init.c \
       swap_commands.c tiny_sort.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
