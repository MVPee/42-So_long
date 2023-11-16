NAME = so_long

LIBFT = srcs/libft
MLX_PATH = srcs/minilibx
MLX = $(MLX_PATH)
MLX_INC = $(MLX_PATH)

SRCS = 	so_long.c \
		srcs/so_long/map_parsing.c \
		srcs/so_long/game_init.c \
		srcs/so_long/map_check.c \
		srcs/so_long/map_path_check.c \
		srcs/so_long/sprite_init.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT) -I$(MLX_INC)
LDFLAGS = -L$(LIBFT) -lft -L$(MLX) -lmlx -framework OpenGL -framework AppKit

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
