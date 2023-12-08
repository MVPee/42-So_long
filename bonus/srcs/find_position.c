/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:04:46 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/08 15:25:35 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static unsigned int	count_map(char **map, char c)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	fill_positions(t_data *data, int **pos, int *y, int *i)
{
	int	x;

	while (data->map[*y])
	{
		x = 0;
		while (data->map[*y][x])
		{
			if (data->map[*y][x] == 'M')
			{
				pos[*i] = (int *)malloc(sizeof(int) * 2);
				if (!pos[*i])
				{
					ft_free_split(1, &pos);
					end_game(data, "Error\nMalloc fail.\n");
				}
				pos[*i][0] = *y;
				pos[*i][1] = x;
				(*i)++;
			}
			x++;
		}
		(*y)++;
	}
}

int	**find_all_position(t_data *data, char c)
{
	int	**pos;
	int	i;
	int	y;

	i = 0;
	y = 0;
	pos = (int **)malloc(sizeof(int *) * (count_map(data->map, c) + 1));
	if (!pos)
		end_game(data, "Error\nMalloc fail.\n");
	fill_positions(data, pos, &y, &i);
	pos[i] = NULL;
	return (pos);
}

int	*find_position(t_data *data, char c)
{
	int	*pos;

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
	ft_free(1, &pos);
	return (NULL);
}
