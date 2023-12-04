/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:04:46 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/04 14:16:44 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static unsigned int count_map(char **map, char c)
{
	unsigned int y;
	unsigned int x;
	unsigned int count;

	count = 0;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int **find_all_position(t_data *data, char c)
{
	int **pos;
	unsigned int count;
	int i = 0;
	int y = 0;
	int x = 0;
	int flag;
	count = count_map(data->map, c);
	ft_printf("count %d\n", count);
	pos = (int **)malloc(sizeof(int *) * (count + 1));
	if (!pos)
		end_game(data, "Error\nMalloc fail.\n");
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if (data->map[y][x] == c)
			{
				pos[i] = (int *)malloc((sizeof(int)) * 2);
				if (!pos[i])
				{
					ft_free_split((void **)pos);
					end_game(data, "Error\nMalloc fail.\n");
				}
				pos[i][0] = y;
				pos[i][1] = x;
				i++;
			}
			x++;
		}
		y++;
	}
	ft_printf("i: %d\n", i);
	pos[i] = NULL;
	return pos;
}

int	*find_position(t_data *data, char c)
{
	int *pos;

	pos = (int *)malloc(sizeof(int) * 2);
	if (!pos)
		end_game(data, "Error\nMalloc fail.\n");
	pos[0] = 0;
	while (data->map[pos[0]])
	{
		pos[1] = 0;
		while (data->map[pos[0]][pos[1]])
		{
			if (data->map[pos[0]][pos[1]] == c)
				return (pos);
			pos[1]++;
		}
		pos[0]++;
	}
	ft_free(pos);
	return (NULL);
}