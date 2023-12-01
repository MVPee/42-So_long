/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:04:46 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/01 12:05:15 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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