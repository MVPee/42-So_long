/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:15 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/29 10:48:47 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/includes/libft.h"
# include <mlx.h>

#ifdef __APPLE__
    #define W 13
    #define A 0
    #define D 2
    #define S 1
    #define ESC 53

//linux
#else
    #define W 119
    #define A 97
    #define D 100
    #define S 115
    #define ESC 65307
#endif

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

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
void			sprite_init(void *mlx, t_sprite *sprite);
void			data_init(t_data *data, t_game game, char **map);

int				map_check(char **map_split, t_game *game);
int				map_path_check(char **map);

int				game_process(int keycode, t_data *data);
void			map_display(void *mlx, void *window, t_sprite sprite,
					char **map_split);
int				end_game(t_data *data, char *message);

#endif