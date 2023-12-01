/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:37:11 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/01 15:56:45 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void player_dead(t_data *data, int *pos)
{
	if(data->map[pos[0] + 1][pos[1]] == 'P')
		end_game(data, "\nYOU DEAD BY EXPLOSION...\n");
	else if(data->map[pos[0] - 1][pos[1]] == 'P')
		end_game(data, "\nYOU DEAD BY EXPLOSION...\n");
	else if(data->map[pos[0]][pos[1] + 1] == 'P')
		end_game(data, "\nYOU DEAD BY EXPLOSION...\n");
	else if(data->map[pos[0]][pos[1] - 1] == 'P')
		end_game(data, "\nYOU DEAD BY EXPLOSION...\n");
}

static void	monster(t_data *data)
{
	static unsigned int	frame;
	int					*pos;

	pos = find_position(data, 'M');
	if (frame % 15 == 0)
		data->data_sprite.monster_current = data->data_sprite.monster1;
	else if (frame % 15 == 1)
		data->data_sprite.monster_current = data->data_sprite.monster2;
	else if (frame % 15 == 2)
		data->data_sprite.monster_current = data->data_sprite.monster3;
	else if (frame % 15 == 3)
		data->data_sprite.monster_current = data->data_sprite.monster4;
	else if (frame % 15 == 5)
		data->data_sprite.monster_current = data->data_sprite.monster5;
	else if (frame % 15 == 6)
		data->data_sprite.monster_current = data->data_sprite.monster6;
	else if (frame % 15 == 7)
		data->data_sprite.monster_current = data->data_sprite.monster7;
	else if (frame % 15 == 8)
		data->data_sprite.monster_current = data->data_sprite.monster8;
	else if (frame % 15 == 9)
		data->data_sprite.monster_current = data->data_sprite.monster9;
	else if (frame % 15 == 10)
		data->data_sprite.monster_current = data->data_sprite.boom1;
	else if (frame % 15 == 11)
	{
		data->data_sprite.monster_current = data->data_sprite.boom2;
		player_dead(data, pos);
	}
	else if (frame % 15 == 12)
	{
		data->data_sprite.monster_current = data->data_sprite.boom3;
		player_dead(data, pos);
	}
	else if (frame % 15 == 13)
	{
		data->data_sprite.monster_current = data->data_sprite.boom4;
		player_dead(data, pos);
	}
	else if (frame % 15 == 14)
		data->data_sprite.monster_current = data->data_sprite.boom5;
	frame++;
}

static void	coin(t_data *data)
{
	static unsigned int	frame;

	if (frame % 5 == 0)
		data->data_sprite.coin_current = data->data_sprite.coin1;
	else if (frame % 5 == 1)
		data->data_sprite.coin_current = data->data_sprite.coin2;
	else if (frame % 5 == 2)
		data->data_sprite.coin_current = data->data_sprite.coin3;
	else if (frame % 5 == 3)
		data->data_sprite.coin_current = data->data_sprite.coin4;
	else if (frame % 5 == 4)
		data->data_sprite.coin_current = data->data_sprite.coin5;
	frame++;
}

static void	display_step(t_data *data)
{
	char	*mv_string;

	mv_string = ft_itoa(data->movement);
	mlx_string_put(data->mlx, data->window, 0, 0, 0xFFFFFF, mv_string);
	ft_free(mv_string);
}

int	animation(t_data *data)
{
	static unsigned int frame;
	if (frame % 5 == 0)
		coin(data);
	if (frame % 7 == 0)
		monster(data);
	frame++;
	map_display(data->mlx, data->window, data->data_sprite, data->map);
	display_step(data);
	usleep(10000);
	return (0);
}