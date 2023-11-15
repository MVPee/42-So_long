NAME = so_long

LIBFT = srcs/libft

SRCS = 	so_long.c \
		srcs/so_long/map_validity.c \
		srcs/so_long/map_init.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L$(LIBFT) -lft

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
