NAME := so_long
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
#MLX_FLAGS := -Imlx_linux -lm -lz -lXext -lX11
LIBFT := my_libft/libft.a
MACROLIBX := MacroLibX/libmlx.so

SRC_DIR := src

SRC := generic_utils.c map_creation.c map_input_validity_checks_utils_1.c \
	map_input_validity_checks_utils_2.c map_input_validity_checks.c \
	map_loading.c map_validity.c so_long.c error_handling.c flood_fill.c \
	store_info.c open_window.c t_game_init.c draw_map_funcs.c\

SRC_FILES := $(addprefix ./$(SRC_DIR)/, $(SRC))

OBJ_DIR := obj
OBJ := $(SRC:.c=.o)
OBJ_FILES := $(addprefix ./$(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(MACROLIBX) $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT) $(MACROLIBX) -lSDL2 -I MacroLibX/includes

$(LIBFT):
	$(MAKE) bonus -C my_libft

$(MACROLIBX):
	$(MAKE) -C MacroLibX -j

./$(OBJ_DIR)/%.o : ./$(SRC_DIR)/%.c
	mkdir -p ./$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C my_libft
	$(MAKE) clean -C MacroLibX -j
	rm -rf ./$(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C my_libft
	$(MAKE) fclean -C MacroLibX

re: fclean all

.PHONY: all clean fclean re


