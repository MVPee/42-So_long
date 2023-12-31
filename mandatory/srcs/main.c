/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:32 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/14 17:00:06 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	mlx_start(t_game game, char **map_split)
{
	t_sprite	sprite;
	t_data		data;

	if ((ft_strlen(map_split[0]) > 24)
		|| (ft_splitlen((const char **)map_split) > 14))
		return (ft_printf_fd(2, "Error\nMap too big.\n"));
	data_init(&data, game, map_split);
	sprite_init(data.mlx, &sprite);
	if (!sprite.coin || !sprite.wall || !sprite.ground || !sprite.player
		|| !sprite.exit)
	{
		mlx_destroy_window(data.mlx, data.window);
		return (ft_printf_fd(2, "Error\nSprites fail.\n"));
	}
	data.data_sprite = sprite;
	map_display(data.mlx, data.window, data.data_sprite, data.map);
	mlx_hook(data.window, 2, 1L << 0, game_process, &data);
	mlx_hook(data.window, 17, 1L << 2, end_game, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	**map_split;
	char	*temp;
	char	**dup;

	if (ac != 2)
		return (ft_printf_fd(2, "Error\nTry: ./so_long maps/map.ber\n"));
	temp = ft_read(open(av[1], O_RDONLY));
	if (!temp)
		return (1);
	map_split = ft_split(temp, "\n");
	ft_free(1, &temp);
	if (!map_split)
		return (ft_printf_fd(2, "Error\nSplit error.\n"));
	game_init(&game);
	dup = ft_splitdup((const char **)map_split);
	if (map_check(map_split, &game) || map_path_check(dup))
	{
		ft_free_matrix(1, &map_split);
		return (1);
	}
	mlx_start(game, map_split);
	return (0);
}
