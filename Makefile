NAME := fdf
CC := gcc
CFLAGS := -Wall -Werror -Wextra

SRC_DIR := src/
OBJ_DIR := obj/

# Libraries
LIBFT_DIR = lib/libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LIB_DIR = $(LIBFT_DIR)
LIB = $(LIBFT)

# Source files
NODE_FOLDER := node/
NODE_FILES := create_node\
	destroy_node\
	edit_node\
	get_interpolation\
	parse_color\
	reset_node

MINILIB_FOLDER := minilib/
MINILIB_FILES := init_minilib\
	exittt\
	key_action\
	draw_line\
	put_pixel

SRC_FILES = $(addprefix $(NODE_FOLDER), $(NODE_FILES))\
	$(addprefix $(MINILIB_FOLDER), $(MINILIB_FILES))\
	main

SRC_DIRECTORIES = $(NODE_FOLDER) $(MINILIB_FOLDER)

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Rules
all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) | $(LIB_DIR)
	$(CC) $(OBJ) $(LIB) -Llib/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB_DIR):
	make -C $(LIB_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(SRC_DIRECTORIES))

re: fclean all

clean:
	rm -rf $(OBJ_DIR)
	@echo "All objects were cleaned up!"

fclean: clean
	rm -f $(NAME)
	@echo "Deleted compiled $(NAME)"
