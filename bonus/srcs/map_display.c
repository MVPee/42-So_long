/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:35:11 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/08 14:12:25 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_display(void *m, void *w, t_sprite s, char **map_split)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = -1;
	while (map_split[++y])
	{
		while (map_split[y][x])
		{
			if (map_split[y][x] == '1')
				mlx_put_image_to_window(m, w, s.wall, 100 * x, 100 * y);
			else if (map_split[y][x] == '0')
				mlx_put_image_to_window(m, w, s.ground, 100 * x, 100 * y);
			else if (map_split[y][x] == 'P')
				mlx_put_image_to_window(m, w, s.player, 100 * x, 100 * y);
			else if (map_split[y][x] == 'C')
				mlx_put_image_to_window(m, w, s.coin_ptr, 100 * x, 100 * y);
			else if (map_split[y][x] == 'E')
				mlx_put_image_to_window(m, w, s.exit_ptr, 100 * x, 100 * y);
			else if (map_split[y][x] == 'M')
				mlx_put_image_to_window(m, w, s.monster_ptr, 100 * x, 100 * y);
			x++;
		}
		x = 0;
	}
}
