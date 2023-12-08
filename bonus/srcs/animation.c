/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:37:11 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/08 14:44:13 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_dead(t_data *data)
{
	int	i;

	i = 0;
	while (data->pos_monster[i])
	{
		if (data->map[data->pos_monster[i][0]
			+ 1][data->pos_monster[i][1]] == 'P')
			end_game(data, "\nYOU EXPLODED...\n");
		else if (data->map[data->pos_monster[i][0]
			- 1][data->pos_monster[i][1]] == 'P')
			end_game(data, "\nYOU EXPLODED...\n");
		else if (data->map[data->pos_monster[i][0]][data->pos_monster[i][1]
			+ 1] == 'P')
			end_game(data, "\nYOU EXPLODED...\n");
		else if (data->map[data->pos_monster[i][0]][data->pos_monster[i][1]
			- 1] == 'P')
			end_game(data, "\nYOU EXPLODED...\n");
		i++;
	}
}

static void	boom(t_data *data, unsigned int frame)
{
	if (frame % 15 == 10)
		data->data_sprite.monster_ptr = data->data_sprite.boom1;
	else if (frame % 15 == 11)
	{
		data->data_sprite.monster_ptr = data->data_sprite.boom2;
		player_dead(data);
	}
	else if (frame % 15 == 12)
	{
		data->data_sprite.monster_ptr = data->data_sprite.boom3;
		player_dead(data);
	}
	else if (frame % 15 == 13)
	{
		data->data_sprite.monster_ptr = data->data_sprite.boom4;
		player_dead(data);
	}
	else if (frame % 15 == 14)
		data->data_sprite.monster_ptr = data->data_sprite.boom5;
}

static void	monster(t_data *data)
{
	static unsigned int	frame;

	if (frame % 15 == 0)
		data->data_sprite.monster_ptr = data->data_sprite.monster1;
	else if (frame % 15 == 1)
		data->data_sprite.monster_ptr = data->data_sprite.monster2;
	else if (frame % 15 == 2)
		data->data_sprite.monster_ptr = data->data_sprite.monster3;
	else if (frame % 15 == 3)
		data->data_sprite.monster_ptr = data->data_sprite.monster4;
	else if (frame % 15 == 5)
		data->data_sprite.monster_ptr = data->data_sprite.monster5;
	else if (frame % 15 == 6)
		data->data_sprite.monster_ptr = data->data_sprite.monster6;
	else if (frame % 15 == 7)
		data->data_sprite.monster_ptr = data->data_sprite.monster7;
	else if (frame % 15 == 8)
		data->data_sprite.monster_ptr = data->data_sprite.monster8;
	else if (frame % 15 == 9)
		data->data_sprite.monster_ptr = data->data_sprite.monster9;
	boom(data, frame);
	frame++;
}

static void	coin(t_data *data)
{
	static unsigned int	frame;

	if (frame % 5 == 0)
		data->data_sprite.coin_ptr = data->data_sprite.coin1;
	else if (frame % 5 == 1)
		data->data_sprite.coin_ptr = data->data_sprite.coin2;
	else if (frame % 5 == 2)
		data->data_sprite.coin_ptr = data->data_sprite.coin3;
	else if (frame % 5 == 3)
		data->data_sprite.coin_ptr = data->data_sprite.coin4;
	else if (frame % 5 == 4)
		data->data_sprite.coin_ptr = data->data_sprite.coin5;
	frame++;
}

int	animation(t_data *data)
{
	static unsigned int	frame;
	char				*mv_string;

	if (frame % 5 == 0)
		coin(data);
	if (frame % 5 == 0)
		monster(data);
	frame++;
	map_display(data->mlx, data->window, data->data_sprite, data->map);
	if (data->movement > ULONG_MAX)
		data->movement = 0;
	mv_string = ft_itoa(data->movement);
	if (!mv_string)
		end_game(data, "Error\nMalloc fail.\n");
	mlx_string_put(data->mlx, data->window, 0, 0, 0xFFFFFF, mv_string);
	ft_free(1, &mv_string);
	usleep(10000);
	return (0);
}
