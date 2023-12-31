/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:35:11 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/29 10:53:12 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_display(void *m, void *w, t_sprite sprite, char **map_split)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_split[y])
	{
		while (map_split[y][x])
		{
			if (map_split[y][x] == '1')
				mlx_put_image_to_window(m, w, sprite.wall, 100 * x, 100 * y);
			else if (map_split[y][x] == '0')
				mlx_put_image_to_window(m, w, sprite.ground, 100 * x, 100 * y);
			else if (map_split[y][x] == 'P')
				mlx_put_image_to_window(m, w, sprite.player, 100 * x, 100 * y);
			else if (map_split[y][x] == 'C')
				mlx_put_image_to_window(m, w, sprite.coin, 100 * x, 100 * y);
			else if (map_split[y][x] == 'E')
				mlx_put_image_to_window(m, w, sprite.exit, 100 * x, 100 * y);
			x++;
		}
		x = 0;
		y++;
	}
}
