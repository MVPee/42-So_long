/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:21:35 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/29 13:19:28 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		data->data_sprite.player = mlx_xpm_file_to_image(data->mlx, path,
			&img_width, &img_height);
	}
	else if (type == 'E')
	{
		if (data->data_sprite.exit)
			mlx_destroy_image(data->mlx, data->data_sprite.exit);
		data->data_sprite.exit = mlx_xpm_file_to_image(data->mlx, path,
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

static int	movement(t_data *d, int y, int x)
{
	int	*p;

	p = player_position(d);
	if (d->map[p[0] + y][p[1] + x] && d->map[p[0] + y][p[1] + x] == '0')
		move_player(d, y, x, p);
	else if (d->map[p[0] + y][p[1] + x] && d->map[p[0] + y][p[1] + x] == 'M')
	{
		ft_free(p);
		end_game(d, "\nYOU DEAD...\n");
	}
	else if (d->map[p[0] + y][p[1] + x] && d->map[p[0] + y][p[1] + x] == 'C')
	{
		move_player(d, y, x, p);
		d->collected++;
		if (d->collected == d->coin)
			sprite_switch(d, 'E', "rscs/open.xpm");
	}
	else if (d->map[p[0] + y][p[1] + x] && d->map[p[0] + y][p[1] + x] == 'E')
	{
		if (d->collected == d->coin)
		{
			ft_free(p);
			end_game(d, "\nSUCCES\n");
		}
	}
	ft_free(p);
	return (1);
}

static void	display_step(t_data *data)
{
	char	*mv_string;

	mv_string = ft_itoa(data->movement);
	mlx_string_put(data->mlx, data->window, 0, 0, 0xFFFFFF, mv_string);
	ft_free(mv_string);
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
		end_game(data, "\nESC\n");
	map_display(data->mlx, data->window, data->data_sprite, data->map);
	display_step(data);
	return (0);
}
