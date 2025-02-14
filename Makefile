NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(FT_PRINTF_DIR) -Iinclude
SRC = src/basic_utils/push_swap_basic_utis.c \
      src/basic_utils/push_swap_stack_utis.c \
      src/basic_utils/push_swap_stack_utis2.c \
      src/basic_utils/push_swap_stack_utis3.c \
      src/chunk/push_swap_chunk_stuff.c \
      src/error/push_swap_error_stuff.c \
      src/error/push_swap_error_stuff2.c \
      src/error/push_swap_error_stuff3.c \
      src/mini_sort/push_swap_mini_sort.c \
      src/movements/push_swap_movements.c \
      src/movements/push_swap_movements2.c \
      src/push_swap_beta.c \
      src/sort/sort_hundred.c \
      src/stack/push_swap_stack_stuff.c \
      src/stack/push_swap_stack_stuff2.c \
      src/stack/push_swap_stack_stuff3.c
OBJDIR = obj/
OBJ = $(SRC:%.c=$(OBJDIR)%.o)
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ft_printf.a

all: ft_printf $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(FT_PRINTF_DIR) -lftprintf

$(OBJDIR)%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR):
	@mkdir -p $(OBJDIR)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re ft_printf