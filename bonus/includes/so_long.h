/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:15 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/04 13:50:19 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/includes/libft.h"
# include <mlx.h>

// Linux
// # define W 119
// # define A 97
// # define D 100
// # define S 115
// # define ESC 65307

// MacOs
# define W 13
# define A 0
# define D 2
# define S 1
# define ESC 53

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
	void		*coin_current;
	void		*coin1;
	void		*coin2;
	void		*coin3;
	void		*coin4;
	void		*coin5;
	void		*wall;
	void		*exit_current;
	void		*exit_open;
	void		*exit_close;
	void		*monster_current;
	void		*monster1;
	void		*monster2;
	void		*monster3;
	void		*monster4;
	void		*monster5;
	void		*monster6;
	void		*monster7;
	void		*monster8;
	void		*monster9;
	void		*boom1;
	void		*boom2;
	void		*boom3;
	void		*boom4;
	void		*boom5;
	void		*dead;
}				t_sprite;

typedef struct s_data
{
	char		**map;
	int			collected;
	int			coin;
	int			movement;
	int			**pos_monster;
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

int				animation(t_data *data);
int				*find_position(t_data *data, char c);
int				**find_all_position(t_data *data, char c);

#endif