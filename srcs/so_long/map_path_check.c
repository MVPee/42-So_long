/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:05:25 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/21 11:40:21 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	check_for_destination(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				free_map(map);
				return (ft_printf_fd(2, "Error\nMap is impossible.\n"));
			}
			x++;
		}
		y++;
	}
	free_map(map);
	return (0);
}

static void	process_path_check(char **map, int x, int y, int *flag)
{
	if (map[y][x] == 'P' && (y > 0 && x > 0))
	{
		if (ft_ischarin(map[y - 1][x], "0EC"))
		{
			map[y - 1][x] = 'P';
			*flag = 1;
		}
		if (ft_ischarin(map[y + 1][x], "0EC"))
		{
			map[y + 1][x] = 'P';
			*flag = 1;
		}
		if (ft_ischarin(map[y][x - 1], "0EC"))
		{
			map[y][x - 1] = 'P';
			*flag = 1;
		}
		if (ft_ischarin(map[y][x + 1], "0EC"))
		{
			map[y][x + 1] = 'P';
			*flag = 1;
		}
	}
}

int	map_path_check(char **map)
{
	int	flag;
	int	x;
	int	y;

	x = 0;
	y = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		while (map[y])
		{
			while (map[y][x])
			{
				process_path_check(map, x, y, &flag);
				x++;
			}
			x = 0;
			y++;
		}
		y = 0;
	}
	return (check_for_destination(map));
}
