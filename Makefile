CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SRCS =  push_swap.c utils.c stack.c index.c swap_functions.c push_functions.c rotate_functions.c reverse_functions.c radix.c simple_sort.c split.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

