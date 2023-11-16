/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:15 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 08:54:39 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../srcs/libft/includes/libft.h"

typedef struct map
{
	int		player;
	int		exit;
	int		coin;
	size_t	len;
}			t_map;

void		map_init(t_map *map);
char		*map_parsing(char *file);
int			map_check(char **map_split, t_map *map);

#endif