/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:05:25 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/08 18:32:38 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_exit(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				if (map[y + 1][x] == 'P')
					return (0);
				if (map[y - 1][x] == 'P')
					return (0);
				if (map[y][x + 1] == 'P')
					return (0);
				if (map[y][x - 1] == 'P')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
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
			if (map[y][x] == 'C')
			{
				ft_free_split(1, &map);
				return (ft_printf_fd(2, "Error\nMap is impossible.\n"));
			}
			x++;
		}
		y++;
	}
	if (check_exit(map))
		return (ft_free_split(1, &map), 1);
	return (ft_free_split(1, &map), 0);
}

static void	process_path_check(char **map, int x, int y, int *flag)
{
	if (map[y][x] == 'P' && (y > 0 && x > 0))
	{
		if (ft_ischarin(map[y - 1][x], "0C"))
		{
			map[y - 1][x] = 'P';
			*flag = 1;
		}
		if (ft_ischarin(map[y + 1][x], "0C"))
		{
			map[y + 1][x] = 'P';
			*flag = 1;
		}
		if (ft_ischarin(map[y][x - 1], "0C"))
		{
			map[y][x - 1] = 'P';
			*flag = 1;
		}
		if (ft_ischarin(map[y][x + 1], "0C"))
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
