NAME=push_swap
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRC=push_swap_beta.c push_swap_chunk_stuff.c push_swap_error_stuff.c push_swap_error_stuff2.c push_swap_movements.c push_swap_movements2.c push_swap_stack_stuff.c push_swap_stack_stuff2.c push_swap_stack_utis.c sort_hundred.c push_swap_stack_utis2.c push_swap_stack_utis3.c push_swap_mini_sort.c push_swap_basic_utis.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re