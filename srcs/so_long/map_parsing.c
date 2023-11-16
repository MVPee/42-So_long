/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:08:31 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 10:38:00 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*map_parsing(char *file)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf_fd(2, "Error\nCannot read file.\n");
		return (NULL);
	}
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		ft_printf_fd(2, "Error\nEmpty map.\n");
		return (NULL);
	}
	while (line)
	{
		temp = map;
		map = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
