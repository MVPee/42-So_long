/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:10:07 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/24 10:40:38 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

void	sprite_init(void *mlx, t_sprite *sprite)
{
	int	img_height;
	int	img_width;

	sprite->coin = mlx_xpm_file_to_image(mlx, "rscs/coin.xpm", &img_width, \
		&img_height);
	sprite->wall = mlx_xpm_file_to_image(mlx, "rscs/wall.xpm", &img_width, \
		&img_height);
	sprite->ground = mlx_xpm_file_to_image(mlx, "rscs/ground.xpm", &img_width, \
		&img_height);
	sprite->player = mlx_xpm_file_to_image(mlx, "rscs/south.xpm", &img_width, \
		&img_height);
	sprite->exit = mlx_xpm_file_to_image(mlx, "rscs/close.xpm", &img_width, \
		&img_height);
}

void	game_init(t_game *game)
{
	game->player = 0;
	game->exit = 0;
	game->coin = 0;
	game->len = 0;
}
