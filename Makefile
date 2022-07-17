NAME = cub3d

SRC_DIR = srcs/

SRC =	parser/check_floor_and_ceiling.c parser/check_settings.c\
		main.c\
		parser/parser.c parser/parse_map.c parser/map_check.c\
		move.c\
		render_next_frame_a.c render_next_frame_b.c\
		rotate.c set_direction.c\
		structs_init.c\
		utils_a.c utils_b.c\
		wall_collision_a.c wall_collision_b.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

FLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lm -Lminilibx -framework OpenGL -framework AppKit

CC = cc

LIBS = libft/libft.a libmlx.a

HDRS = -I minilibx -I libft/includes -I includes/

OBJS := $(SRCS:.c=.o)

OPT_FLAGS = -O2

all: $(NAME)
	./cub3d maps/test1.cub

$(NAME): $(OBJS)
	@$(MAKE) -C  libft/ all
	@$(MAKE) -C minilibx/ all
	@mv minilibx/libmlx.a ./libmlx.a
	@$(CC) $(LIBS) $(HDRS) $(MLX_FLAGS) $(FLAGS) -o $@ $^
	@echo "\033[1m\033[32mSuccessfully Compiled\033[39m"

%.o: %.c
	@$(CC) -o $@ -c $<  $(HDRS) $(FLAGS)

clean: 
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx/ clean
	@rm $(OBJS)
	@echo "\033[1m\033[33mCleaning Object Files\033[39m"

fclean:
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C minilibx/ clean
	@rm -f $(OBJS)
	@rm -f libmlx.a
	@rm -f $(NAME)
	@echo "\033[1m\033[31mPurged Objects and Executables\033[39m"

norm:
	norminette srcs/ includes/ libft/

re: fclean all

.PHONY: all clean fclean re cub3d norm
