NAME		= cub3D

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= lib/libft
MLX_DIR		= lib/minilibx-linux

LIBFT		= $(LIBFT_DIR)/libft.a
FT_PRINTF	= $(LIBFT_DIR)/ft_printf/libftprintf.a
MLX			= $(MLX_DIR)/libmlx.a

INCLUDES	= -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS		= -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf \
			  -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS		= src/main/main.c \
			  src/main/preflight_check.c \
			  src/error/print_err.c \
			  src/parse/init.c \
			  src/parse/read_and_store.c \
			  src/parse/free.c \
			  src/parse/parse.c \
			  src/parse/parse_map.c \
			  src/parse/scan_line.c \
			  src/parse/scan_line_utils.c \
			  src/parse/parse_element_line.c \
			  src/parse/parse_color_value.c \
			  src/parse/validate.c \
			  src/parse/validate_textures.c \
			  src/parse/validate_cells.c \
			  src/parse/validate_map_closed.c \
			  src/game/start_game.c \
			  src/game/init_game.c \
			  src/game/textures.c \
			  src/game/camera.c \
			  src/game/hooks.c \
			  src/game/input.c \
			  src/game/mouse.c \
			  src/game/free.c \
			  src/game/render.c \
			  src/game/raycast.c \
			  src/game/wall_render.c

OBJS		= $(SRCS:.c=.o)

MAP			= maps/valid/subject_map.cub

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF): $(LIBFT)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run: all
	./$(NAME) $(MAP)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
		--errors-for-leak-kinds=all ./$(NAME) $(MAP)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all run valgrind clean fclean re
