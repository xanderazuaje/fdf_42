NAME := fdf
CC := gcc
CFLAGS := -Wall -Werror -Wextra

SRC_DIR := src/
OBJ_DIR := obj/

#libraries
LIBFT_DIR = lib/libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LIB_DIR = $(LIBFT_DIR)
LIB = $(LIBFT)

# Source files
NODE_FOLDER := node/
NODE_FILES := $(addprefix $(NODE_FOLDER), \
	create_coords\
	create_node\
	parse_color\
	)

SRC_FILES = $(NODE_FILES)
SRC_DIRECTORIES = $(NODE_FOLDER)

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ =  $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#RULES
all:
	@$(MAKE) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_DIR) $(SRC_DIRECTORIES) $(OBJ) 
	$(CC) $(OBJ) $(LIB) -Llib/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)	

$(LIB_DIR):
	make -C $(LIB_DIR)

$(SRC_DIRECTORIES):
	@echo creating directories 
	@mkdir -p $(addprefix $(OBJ_DIR), $(SRC_DIRECTORIES))


re: clean all

clean:
	@rm -rf $(OBJ_DIR)*
	@echo all objects were cleaned up!

fclean: clean
	@rm $(NAME)
	@echo deleted compiled SRC_FILES