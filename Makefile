NAME=push_swap
CC=cc
CFLAGS=	-Wall -Wextra -Werror -I$(FT_PRINTF_DIR)
SRC=push_swap_beta.c push_swap_chunk_stuff.c push_swap_error_stuff.c push_swap_error_stuff2.c push_swap_movements.c push_swap_movements2.c push_swap_stack_stuff.c push_swap_stack_stuff2.c push_swap_stack_utis.c sort_hundred.c push_swap_stack_utis2.c push_swap_stack_utis3.c push_swap_mini_sort.c push_swap_basic_utis.c
OBJ=$(SRC:.c=.o)
FT_PRINTF_DIR=./ft_printf
FT_PRINTF_LIB=$(FT_PRINTF_DIR)/ft_printf.a

all:	ft_printf	$(NAME)

$(NAME):	$(OBJ)
	@$(CC)	$(CFLAGS)	-o	$@	$^	-L$(FT_PRINTF_DIR)	-lftprintf

%.o:	%.c
	@$(CC)	$(CFLAGS)	-c	$<	-o	$@

ft_printf:
	@$(MAKE)	-C	$(FT_PRINTF_DIR)

clean:
	@rm	-f	$(OBJ)
	@$(MAKE)	-C	$(FT_PRINTF_DIR)	clean

fclean:	clean
	@rm	-f	$(NAME)
	@$(MAKE)	-C	$(FT_PRINTF_DIR)	fclean

re:	fclean	all

.PHONY:	all	clean	fclean	re	ft_printf