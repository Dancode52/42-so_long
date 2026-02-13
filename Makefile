NAME := so_long
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
LIBFT := libft.a

SRC_DIR := src
SRC := so_long.c map_parsing.c
SRC_FILES := $(addprefix ./$(SRC_DIR)/, $(SRC))

OBJ_DIR := obj
OBJ := $(SRC:.c=.o)
OBJ_FILES := $(addprefix ./$(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(LIBFT) directory $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C libft/42-Libft

./$(OBJ_DIR)/%.o : ./$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

directory:
	mkdir -p ./$(OBJ_DIR)

clean:
	$(MAKE) clean -C libft/42-Libft
	rm -rf ./$(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/42-Libft

re: fclean all

.PHONY: all clean fclean re libft.a directory


