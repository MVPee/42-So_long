# Nom de l'exécutable à générer
NAME = so_long

# Chemin vers la libft
LIBFT = ./srcs/libft

# Fichiers sources de so_long
SRCS = 	so_long.c \
		srcs/so_long/map_validity.c \
		srcs/so_long/map_init.c

# Objets (fichiers .o correspondants aux fichiers sources)
OBJS = $(SRCS:.c=.o)

# Flags de compilation, inclure -I pour les headers de libft si nécessaire
CFLAGS = -Wall -Wextra -Werror

# Compiler avec la libft
LDFLAGS = -L$(LIBFT) -lft

# Compilation de la libft
$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

# Compilation de so_long
$(NAME): $(OBJS) $(LIBFT)/libft.a
	gcc $(OBJS) $(LDFLAGS) -o $(NAME)

# Règle pour compiler chaque fichier .o à partir de son .c
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

# Règle all
all: $(NAME)

# Règle clean
clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

# Règle fclean
fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

# Règle re
re: fclean all

# Phony targets
.PHONY: all clean fclean re
