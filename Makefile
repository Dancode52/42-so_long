NAME := so_long
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
LIBFT := my_libft/libft.a

SRC_DIR := src

SRC := generic_utils.c map_creation.c map_input_validity_checks_utils_1.c \
	map_input_validity_checks_utils_2.c map_input_validity_checks.c \
	map_loading.c map_validity.c so_long.c\

SRC_FILES := $(addprefix ./$(SRC_DIR)/, $(SRC))

OBJ_DIR := obj
OBJ := $(SRC:.c=.o)
OBJ_FILES := $(addprefix ./$(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C my_libft

./$(OBJ_DIR)/%.o : ./$(SRC_DIR)/%.c
	mkdir -p ./$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C my_libft
	rm -rf ./$(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C my_libft

re: fclean all

.PHONY: all clean fclean re


