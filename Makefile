# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
MINILIB_DIR := $(SRC_DIR)/minilib
NODE_DIR := $(SRC_DIR)/node
MLX_DIR := $(LIB_DIR)/mlx
LIBFT_DIR := $(LIB_DIR)/libft

# Source files
SRC_FILES := $(SRC_DIR)/main.c \
             $(MINILIB_DIR)/draw_line.c \
             $(MINILIB_DIR)/exittt.c \
             $(MINILIB_DIR)/get_interpolation.c \
             $(MINILIB_DIR)/init_minilib.c \
             $(MINILIB_DIR)/key_action.c \
             $(MINILIB_DIR)/parse_color.c \
             $(MINILIB_DIR)/put_pixel.c \
             $(MINILIB_DIR)/set_minilib.c \
             $(MINILIB_DIR)/mouse_handler.c \
             $(MINILIB_DIR)/get_percent.c\
             $(NODE_DIR)/create_node.c \
             $(NODE_DIR)/edit_node.c \
             $(NODE_DIR)/create_matrix.c \
             $(NODE_DIR)/calculate_position.c \
             $(NODE_DIR)/draw_matrix.c \

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBS := -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Executable
TARGET := fdf

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Libft targets
libft:
	$(MAKE) -C $(LIBFT_DIR)

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

# Phony targets
.PHONY: all clean fclean re libft libft_clean libft_fclean

all: libft $(TARGET)

clean: libft_clean
	rm -rf $(OBJ_DIR)

fclean: clean libft_fclean
	rm -f $(TARGET)

re: fclean all