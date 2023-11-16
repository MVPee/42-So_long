/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:24:33 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 13:26:48 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	map_line_check(char *line, size_t len, int nbTable, int count)
{
	int	j;

    if (len != ft_strlen(line))
        return (ft_printf_fd(2, "Error\nMap is not a perfect retangle\n"));
    j = 0;
	if (count == 0 || count == (nbTable - 1))
	{
		while (line[j])
		{
			if (line[j] != '1')
				return (ft_printf_fd(2, "Error\nInvalid border. L: %d C %d\n",
						count + 1, j + 1));
			j++;
		}
	}
    else if (line[0] != '1' || line[len-1] != '1')
        return (ft_printf_fd(2, "Error\nInvalid border. L: %d\n", count + 1));
	return (0);
}

static int map_item_check(char *line, t_game *game)
{
    int i;

    i = 0;
    while(line[i])
    {
        if(line[i] == 'P')
            game->player += 1;
        else if(line[i] == 'C')
            game->coin += 1;
        else if(line[i] == 'E')
            game->exit += 1;
        else if(line[i] != '1' && line[i] != '0' && line[i] != '\n')
            return (ft_printf_fd(2, "Error\nInvalid character. C %d\n", i + 1));
        i++;
    }
    return (0);
}

int	map_check(char **map_split, t_game *game)
{
	int	count;
	int	nbTable;
	size_t	len;

	nbTable = 0;
	while (map_split[nbTable])
		nbTable++;
	len = ft_strlen(map_split[0]);
	count = 0;
	while (map_split[count])
	{
		if (map_line_check(map_split[count], len, nbTable, count))
			return (1);
        if (map_item_check(map_split[count], game))
            return (1);
		count++;
	}
    if(game->player != 1 || game->coin <= 0 || game->exit != 1)
        return (ft_printf_fd(2, "Error\nNumber of item is incorrect. P %d C %d E %d\n", game->player, game->coin, game->exit));
	return (0);
}
