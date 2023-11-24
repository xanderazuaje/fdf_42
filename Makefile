NAME := fdf

SRC_DIR := src/
OBJ_DIR := obj/

SRC_FILES = a

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ =  $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


CC := gcc
CFLAGS := -Wall -Werror -Wextra


all:
	@$(MAKE) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L mlx -l mlx -framework OpenGL -framework AppKit -o $(NAME)	

clean:
	@rm -rf $(OBJ_DIR)*
	@echo all objects were cleaned up!

fclean: clean
	@rm $(NAME)
	@echo deleted compiled SRC_FILES