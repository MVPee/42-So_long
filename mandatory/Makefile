NAME = so_long

LIBFT = ../libft

SRCS = 	srcs/main.c \
		srcs/game.c \
		srcs/map_check.c \
		srcs/map_path_check.c \
		srcs/map_display.c \
		srcs/init.c \
		srcs/end_game.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I$(LIBFT)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    LDFLAGS = -L$(LIBFT) -lft -lmlx -lXext -lX11 -lm
else
    LDFLAGS = -L$(LIBFT) -lft -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	gcc $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

run: all
	./so_long maps/defi.ber

.PHONY: all clean fclean re
