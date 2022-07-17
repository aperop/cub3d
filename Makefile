NAME = cub3d

HEADERS = includes/*.h

SRC_DIR = srcs

OBJ_DIR	= objs

SRC =	$(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)

OBJ =	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = libft/libft.a minilibx/libmlx.a

INC = -I ./includes -I ./minilibx -I ./libft/includes

LIBS_FLAGS = -L ./libft -lft -L ./minilibx -lmlx -framework OpenGL -framework AppKit




all:		$(NAME)

$(NAME):	$(OBJ)
				$(CC) $(CFLAGS) $(INC) $(LIBS_FLAGS) $^ -o $@
				@echo "\033[1m\033[32mAll successfully compiled\033[39m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBS) $(HEADERS)
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(@:/$(notdir $@)=)
				$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
				@make -C libft/
				@make -C minilibx/

clean: 
				rm -rf $(OBJ_DIR)
				make clean -C libft/
				make clean -C minilibx/
				@echo "\033[1m\033[33mCleaning Object Files\033[39m"

fclean:		clean
				make fclean -C libft/
				rm -f $(NAME)
				@echo "\033[1m\033[31mPurged Objects and Executables\033[39m"

norm:
				norminette libft/ srcs/ includes/

re: fclean all

.PHONY: all clean fclean re cub3d norm
