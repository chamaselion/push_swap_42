NAME=push_swap
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=push_swap_beta.c push_swap_movements.c push_swap_stack_utis.c sort_hundred.c sort_more_than_hundred.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@del -f $(OBJ)

fclean: clean
	@del -f $(NAME)

re: fclean all

.PHONY: all clean fclean re