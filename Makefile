NAME := so_long
NAME_BONUS := so_long_bonus
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
LIBFT := my_libft/libft.a
MACROLIBX := MacroLibX/libmlx.so

SRC_DIR := src
SRC_BONUS_DIR := src_bonus

SRC := generic_utils.c map_creation.c map_input_validity_checks_utils_1.c \
	map_input_validity_checks_utils_2.c map_input_validity_checks.c \
	map_loading.c map_validity.c so_long.c error_handling.c flood_fill.c \
	store_info.c open_window.c t_game_init.c draw_map_funcs1.c \
	draw_map_funcs2.c player_movement.c\

SRC_BONUS := generic_utils_bonus.c map_creation_bonus.c map_input_validity_checks_utils_1_bonus.c \
	map_input_validity_checks_utils_2_bonus.c map_input_validity_checks_bonus.c \
	map_loading_bonus.c map_validity_bonus.c so_long_bonus.c error_handling_bonus.c flood_fill_bonus.c \
	store_info_bonus.c open_window_bonus.c t_game_init_bonus.c draw_map_funcs1_bonus.c \
	draw_map_funcs2_bonus.c player_movement_bonus.c\

SRC_FILES := $(addprefix ./$(SRC_DIR)/, $(SRC))
SRC_BONUS_FILES := $(addprefix ./$(SRC_DIR)/, $(SRC_BONUS))

OBJ_DIR := obj
OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)
OBJ_FILES := $(addprefix ./$(OBJ_DIR)/, $(OBJ))
OBJ_BONUS_FILES := $(addprefix ./$(OBJ_DIR)/, $(OBJ_BONUS))

all: $(NAME)

$(NAME): $(MACROLIBX) $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT) $(MACROLIBX) -lSDL2 -I MacroLibX/includes

$(LIBFT):
	$(MAKE) bonus -C my_libft

$(MACROLIBX):
	$(MAKE) -C MacroLibX -j

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MACROLIBX) $(LIBFT) $(OBJ_BONUS_FILES)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS_FILES) $(LIBFT) $(MACROLIBX) -lSDL2 -I MacroLibX/includes

./$(OBJ_DIR)/%.o : ./$(SRC_DIR)/%.c
	mkdir -p ./$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

./$(OBJ_DIR)/%.o : ./$(SRC_BONUS_DIR)/%.c
	mkdir -p ./$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C my_libft
	$(MAKE) clean -C MacroLibX -j
	rm -rf ./$(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C my_libft
	$(MAKE) fclean -C MacroLibX

re: fclean all

.PHONY: all clean fclean re


