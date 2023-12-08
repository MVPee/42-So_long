/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:10:07 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/08 15:07:42 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	data_init(t_data *data, t_game game, char **map)
{
	data->map = map;
	data->collected = 0;
	data->coin = game.coin;
	data->movement = 0;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, ft_strlen(map[0]) * 100, \
		ft_splitlen((const char **)map) * 100, "So long");
	data->data_game = game;
}

void	sprite_monster(void *mlx, t_sprite *sprite)
{
	int	img_height;
	int	img_width;

	sprite->coin1 = mlx_xpm_file_to_image(mlx, "rscs/coin1.xpm", &img_width, \
		&img_height);
	sprite->coin2 = mlx_xpm_file_to_image(mlx, "rscs/coin2.xpm", &img_width, \
		&img_height);
	sprite->coin3 = mlx_xpm_file_to_image(mlx, "rscs/coin3.xpm", &img_width, \
		&img_height);
	sprite->coin4 = mlx_xpm_file_to_image(mlx, "rscs/coin4.xpm", &img_width, \
		&img_height);
	sprite->coin5 = mlx_xpm_file_to_image(mlx, "rscs/coin5.xpm", &img_width, \
		&img_height);
	sprite->coin_ptr = sprite->coin1;
}

void	sprite_coin(void *mlx, t_sprite *sprite)
{
	int	img_height;
	int	img_width;

	sprite->monster1 = mlx_xpm_file_to_image(mlx, "rscs/monster1.xpm", \
		&img_width, &img_height);
	sprite->monster2 = mlx_xpm_file_to_image(mlx, "rscs/monster2.xpm", \
		&img_width, &img_height);
	sprite->monster3 = mlx_xpm_file_to_image(mlx, "rscs/monster3.xpm", \
		&img_width, &img_height);
	sprite->monster4 = mlx_xpm_file_to_image(mlx, "rscs/monster4.xpm", \
		&img_width, &img_height);
	sprite->monster5 = mlx_xpm_file_to_image(mlx, "rscs/monster5.xpm", \
		&img_width, &img_height);
	sprite->monster6 = mlx_xpm_file_to_image(mlx, "rscs/monster6.xpm", \
		&img_width, &img_height);
	sprite->monster7 = mlx_xpm_file_to_image(mlx, "rscs/monster7.xpm", \
		&img_width, &img_height);
	sprite->monster8 = mlx_xpm_file_to_image(mlx, "rscs/monster8.xpm", \
		&img_width, &img_height);
	sprite->monster9 = mlx_xpm_file_to_image(mlx, "rscs/monster9.xpm", \
		&img_width, &img_height);
	sprite->monster_ptr = sprite->monster1;
}

void	sprite_init(void *mlx, t_sprite *sprite)
{
	int	img_height;
	int	img_width;

	sprite->wall = mlx_xpm_file_to_image(mlx, "rscs/wall.xpm", &img_width, \
		&img_height);
	sprite->ground = mlx_xpm_file_to_image(mlx, "rscs/ground.xpm", &img_width, \
		&img_height);
	sprite->player = mlx_xpm_file_to_image(mlx, "rscs/south.xpm", &img_width, \
		&img_height);
	sprite->exit_open = mlx_xpm_file_to_image(mlx, "rscs/open.xpm", &img_width, \
		&img_height);
	sprite->exit_close = mlx_xpm_file_to_image(mlx, "rscs/close.xpm", \
		&img_width, &img_height);
	sprite->exit_ptr = sprite->exit_close;
	sprite->boom1 = mlx_xpm_file_to_image(mlx, "rscs/boom1.xpm", &img_width, \
		&img_height);
	sprite->boom2 = mlx_xpm_file_to_image(mlx, "rscs/boom2.xpm", &img_width, \
		&img_height);
	sprite->boom3 = mlx_xpm_file_to_image(mlx, "rscs/boom3.xpm", &img_width, \
		&img_height);
	sprite->boom4 = mlx_xpm_file_to_image(mlx, "rscs/boom4.xpm", &img_width, \
		&img_height);
	sprite->boom5 = mlx_xpm_file_to_image(mlx, "rscs/boom5.xpm", &img_width, \
		&img_height);
}

void	game_init(t_game *game)
{
	game->player = 0;
	game->exit = 0;
	game->coin = 0;
	game->len = 0;
}
