NAME = so_long

LIBFT = ../libft
# MLX_PATH = ../../minilibx
# MLX = $(MLX_PATH)
# MLX_INC = $(MLX_PATH)

SRCS = 	srcs/main.c \
		srcs/game.c \
		srcs/map_check.c \
		srcs/map_path_check.c \
		srcs/map_display.c \
		srcs/init.c \
		srcs/end_game.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I$(LIBFT)
LDFLAGS = -L$(LIBFT) -lft -lmlx -framework OpenGL -framework AppKit
# LDFLAGS = -L$(LIBFT) -lft -lmlx -lXext -lX11 -lm

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
