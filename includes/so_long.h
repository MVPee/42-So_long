/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:15 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/20 12:08:05 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../srcs/libft/includes/libft.h"
# include <mlx.h>

# define W 13
# define A 0
# define D 2
# define S 1
# define ESC 53

typedef struct s_game
{
	int			player;
	int			exit;
	int			coin;
	size_t		len;
}				t_game;

typedef struct s_sprite
{
	void		*player;
	void		*ground;
	void		*coin;
	void		*wall;
	void		*exit;
}				t_sprite;

typedef struct s_data
{
	char		**map;
	int			collected;
	int			coin;
	int			movement;
	void		*mlx;
	void		*window;
	t_sprite	data_sprite;
	t_game		data_game;
}				t_data;

void			game_init(t_game *game);
int				map_check(char **map_split, t_game *game);
int				map_path_check(char **map);
void			sprite_init(void *mlx, t_sprite *sprite);
void			map_display(void *mlx, void *window, t_sprite sprite,
					char **map_split);
void			data_init(t_data *data, t_sprite sprite, t_game game,
					char **map, void *mlx, void *window);
int				*player_position(char **map);

#endif