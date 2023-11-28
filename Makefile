NAME = so_long

LIBFT = srcs/libft
# MLX_PATH = ../../minilibx
# MLX = $(MLX_PATH)
# MLX_INC = $(MLX_PATH)

SRCS = 	so_long.c \
		srcs/so_long/game.c \
		srcs/so_long/map_check.c \
		srcs/so_long/map_path_check.c \
		srcs/so_long/map_display.c \
		srcs/so_long/init.c \
		srcs/so_long/end_game.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I$(LIBFT)
# LDFLAGS = -L$(LIBFT) -lft -lmlx -framework OpenGL -framework AppKit
LDFLAGS = -L$(LIBFT) -lft -lmlx -lXext -lX11 -lm

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	gcc $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
