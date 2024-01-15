# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
MINILIB_DIR := $(SRC_DIR)/minilib
NODE_DIR := $(SRC_DIR)/node
PARSER_DIR := $(SRC_DIR)/parser
MLX_DIR := $(LIB_DIR)/mlx
LIBFT_DIR := $(LIB_DIR)/libft

# Source files
SRC_FILES := $(SRC_DIR)/main.c \
             $(MINILIB_DIR)/draw_line.c \
             $(MINILIB_DIR)/exittt.c \
             $(MINILIB_DIR)/get_interpolation.c \
             $(MINILIB_DIR)/init_minilib.c \
             $(MINILIB_DIR)/key_action.c \
             $(MINILIB_DIR)/put_pixel.c \
             $(MINILIB_DIR)/set_minilib.c \
             $(MINILIB_DIR)/mouse_handler.c \
             $(MINILIB_DIR)/get_percent.c\
             $(NODE_DIR)/create_node.c \
             $(NODE_DIR)/create_matrix.c \
             $(NODE_DIR)/calculate_position.c \
             $(NODE_DIR)/draw_matrix.c \
             $(PARSER_DIR)/parser.c \
             $(PARSER_DIR)/parse_color.c \
             $(PARSER_DIR)/get_next_line.c \
             $(PARSER_DIR)/parse_input.c \
             $(PARSER_DIR)/handle_parse_line_error.c \
             $(PARSER_DIR)/handle_parsing_error.c \
             $(PARSER_DIR)/iterate_and_parse.c \
             $(PARSER_DIR)/free_parser.c \
             $(PARSER_DIR)/parser_validators.c \

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBS := -L$(MLX_DIR) -L$(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit

# Executable
TARGET := fdf


all: libft $(TARGET)

# Libft targets
libft:
	$(MAKE) -C $(LIBFT_DIR)

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

clean: libft_clean
	rm -rf $(OBJ_DIR)

fclean: clean libft_fclean
	rm -f $(TARGET)

re: fclean all

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean re