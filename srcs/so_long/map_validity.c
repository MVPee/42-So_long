/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:23:26 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/15 15:47:49 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	validity_check(char *line, t_map *map)
{
	int	i;
    size_t len;

    len = ft_strlen(line);
	i = 0;
	if (map->len != len)
		return (ft_printf_fd(2, "Error\nMap is not a perfect rectangle.\n"));
    if (line[0] != '1' || line[len - 2] != '1')
        return (ft_printf_fd(2, "Error\nBorder is incorrect.\n"));
	while (line[i])
	{
		if (line[i] == 'P')
			map->player += 1;
		else if (line[i] == 'E')
			map->exit += 1;
		else if (line[i] == 'C')
			map->coin += 1;
		else if (line[i] != '1' && line[i] != '0' && line[i] != '\n')
			return (ft_printf_fd(2, "Error\nMap is incorrect: %c.\n", line[i]));
		i++;
	}
	return (0);
}
int	first_last_border_check(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] != '1' && line[i] != '\n')
            return (1);
        i++;
    }
    return (0);
}

int	map_validity(char *file, t_map *map)
{
	int		fd;
	int		flag;
	char	*line;

	flag = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (ft_printf_fd(2, "Error\nCannot read file.\n"));
	line = get_next_line(fd);
    if (!line)
        return (ft_printf_fd(2, "Error\nEmpty file.\n"));
    if (first_last_border_check(line))
        return (ft_printf_fd(2, "Error\nBorder is incorrect.\n"));
	map->len = ft_strlen(line);
	while (line)
	{
		if (validity_check(line, map))
		{
			free(line);
			return (1);
        }
		free(line);
		line = get_next_line(fd);
	}
    // if (first_last_border_check(line))
    //     return (ft_printf_fd(2, "Error\nBorder is incorrect.\n"));
	if (map->player != 1 || map->coin <= 0 || map->exit != 1)
		return (ft_printf_fd(2, "Error\nMap is incorrect\nStart: %d\nCoin: %d\nExit: %d\n", map->player, map->exit, map->coin));
	return (0);
}
