/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:21:35 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/24 12:39:56 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	*player_position(t_data *data)
{
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	if (!pos)
		end_game(data, "Error\nWhere is Player?");
	pos[0] = 0;
	while (data->map[pos[0]])
	{
		pos[1] = 0;
		while (data->map[pos[0]][pos[1]])
		{
			if (data->map[pos[0]][pos[1]] == 'P')
				return (pos);
			pos[1]++;
		}
		pos[0]++;
	}
	ft_free(pos);
	return (NULL);
}

static void	sprite_switch(t_data *data, char type, char *path)
{
	int	img_height;
	int	img_width;

	if (type == 'P')
	{
		if (data->data_sprite.player)
			mlx_destroy_image(data->mlx, data->data_sprite.player);
		data->data_sprite.player = mlx_xpm_file_to_image(data->mlx, path, \
			&img_width, &img_height);
	}
	else if (type == 'E')
	{
		if (data->data_sprite.exit)
			mlx_destroy_image(data->mlx, data->data_sprite.exit);
		data->data_sprite.exit = mlx_xpm_file_to_image(data->mlx, path, \
			&img_width, &img_height);
	}
	if (!data->data_sprite.player || !data->data_sprite.exit)
		end_game(data, "Error\nSprites fail.\n");
}

static void	move_player(t_data *data, int y, int x, int *pos)
{
	data->map[pos[0]][pos[1]] = '0';
	data->map[pos[0] + y][pos[1] + x] = 'P';
}

static int	movement(t_data *data, int y, int x)
{
	int	*pos;

	pos = player_position(data);
	if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] \
		+ x] == '0')
		move_player(data, y, x, pos);
	else if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] \
		+ x] == 'C')
	{
		move_player(data, y, x, pos);
		data->collected++;
		if (data->collected == data->coin)
			sprite_switch(data, 'E', "rscs/open.xpm");
	}
	else if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] \
		+ x] == 'E')
	{
		if (data->collected == data->coin)
		{
			ft_free(pos);
			end_game(data, "\nSUCCES");
		}
	}
	ft_free(pos);
	return (1);
}

int	game_process(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
	{
		data->movement += movement(data, -1, 0);
		sprite_switch(data, 'P', "rscs/north.xpm");
	}
	else if (keycode == S || keycode == DOWN)
	{
		data->movement += movement(data, 1, 0);
		sprite_switch(data, 'P', "rscs/south.xpm");
	}
	else if (keycode == A || keycode == LEFT)
	{
		data->movement += movement(data, 0, -1);
		sprite_switch(data, 'P', "rscs/west.xpm");
	}
	else if (keycode == D || keycode == RIGHT)
	{
		data->movement += movement(data, 0, 1);
		sprite_switch(data, 'P', "rscs/east.xpm");
	}
	else if (keycode == ESC)
		end_game(data, "\nESC");
	map_display(data->mlx, data->window, data->data_sprite, data->map);
	ft_printf("Step(s): %d\n", data->movement);
	return (0);
}
