# Detect the operating system
UNAME_S := $(shell uname -s)

# Default variables
NAME = so_long
SRCS = $(wildcard srcs/*/*.c)
HEADER = -Iincludes
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
CC = cc
CFLAGS = -g
# -Wall -Wextra -Werror

# OS settings
ifeq ($(UNAME_S), Linux)
    # Linux flags
    MLX_DIR = mlx/
    MLX = $(MLX_DIR)libmlx_Linux.a
    MLX_FLAGS = -lmlx -L/usr/lib -lXext -lX11 -lm #-lmlx -lX11 -lXext -lm
else ifeq ($(UNAME_S), Darwin)
    # macOS flags
    MLX_DIR = mlx/
    MLX = $(MLX_DIR)libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    $(error Unsupported OS: $(UNAME_S))
endif

# Terminal Colors
GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
AQUA = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX)
	@echo "\n$(YELLOW)Setting DISPLAY ENV...$(RESET)"
	@echo "$(GREEN)DISPLAY ENV set to :0$(RESET)"
	@echo "$(YELLOW)\nCompiling so_long executable...$(RESET)"
	@# @echo "export DISPLAY=:0" >> ~/.bashrc
	@$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)
	@echo "$(AQUA)so_long executable compiled$(RESET)"

$(LIBFT): FORCE
	@echo "\n$(YELLOW)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) -s

$(MLX): FORCE
	@echo "\n$(YELLOW)Compiling minilibx...$(RESET)"
	@make -C $(MLX_DIR) -s > /dev/null 2>&1
	@echo "$(GREEN)minilibx compiled$(RESET)"

clean:
	@make clean -C $(LIBFT_DIR) -s
	@make clean -C $(MLX_DIR) -s
	@rm -rf $(OBJS_DIR)
	@echo "$(PURPLE)clean successful$(RESET)"

fclean: clean
	@clear
	@make fclean -C $(LIBFT_DIR) -s
	@rm -f $(NAME)
	@echo "$(PURPLE)fclean successful$(RESET)"

clear:
	@clear

re: clear fclean all

test:
	./so_long assets/maps/valid/map_valid_2.ber

val:
	valgrind ./so_long assets/maps/valid/map_valid_2.ber

seg:
	valgrind --tool=memcheck --track-origins=yes --error-exitcode=1 --leak-check=no ./so_long assets/maps/valid/map_valid_2.ber

FORCE:

.PHONY: all clean fclean re
