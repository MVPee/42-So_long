/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:15 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 13:27:37 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../srcs/libft/includes/libft.h"
# include <mlx.h>

typedef struct game
{
	int		player;
	int		exit;
	int		coin;
	size_t	len;
}			t_game;

void		game_init(t_game *game);
char		*map_parsing(char *file);
int			map_check(char **map_split, t_game *game);
int			map_path_check(char **map_split);

#endif