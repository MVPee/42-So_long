/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:32 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 13:56:11 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// static int	free_map_split(char ***map_split)
// {
// 	int	i;

// 	i = 0;
// 	while (map_split[i])
// 	{
// 		free(map_split[i]);
// 		i++;
// 	}
// 	free(map_split);
// 	return (1);
// }

static int mlx_test(t_sprite *sprite, char **map_split)
{
    void    *mlx;
    void    *window;
    int x;
    int y;

    mlx = mlx_init();
    y = 0;
    while(map_split[y])
        y++;
    window = mlx_new_window(mlx, ft_strlen(map_split[0]) * 100, y * 100, "So long");
    sprite_init(mlx, sprite);
    if (!sprite->coin || !sprite->wall || !sprite->ground || !sprite->player || !sprite->exit)
    {
        mlx_destroy_window(mlx, window);
        return 1;
    }
	// mlx_put_image_to_window(mlx, window, sprite->exit, 0, 0);
    // mlx_put_image_to_window(mlx, window, sprite->ground, 0, 100);
	// mlx_put_image_to_window(mlx, window, sprite->player, 0, 200);
    // mlx_put_image_to_window(mlx, window, sprite->wall, 0, 300);
    x = 0;
    y = 0;
    while(map_split[y])
    {
        while(map_split[y][x])
        {
            if(map_split[y][x] == '1')
                mlx_put_image_to_window(mlx, window, sprite->wall, 100 * x, 100 * y);
            else if(map_split[y][x] == '0')
                mlx_put_image_to_window(mlx, window, sprite->ground, 100 * x, 100 * y);
            else if(map_split[y][x] == 'P')
                mlx_put_image_to_window(mlx, window, sprite->player, 100 * x, 100 * y);
            else if(map_split[y][x] == 'C')
                mlx_put_image_to_window(mlx, window, sprite->coin, 100 * x, 100 * y);
            else if(map_split[y][x] == 'E')
                mlx_put_image_to_window(mlx, window, sprite->exit, 100 * x, 100 * y);
            x++;
        }
        x = 0;
        y++;
    }
    ft_printf("x %d, y %d\n", x, y);
    mlx_loop(mlx);

    return 0;
}

int	main(int ac, char **av)
{
	t_game	game;
    t_sprite	sprite;
	char	**map_split;
	char 	*temp;

	if (ac != 2)
		return (ft_printf_fd(2, "Error\nTry: ./so_long maps/map.ber\n"));
	temp = map_parsing(av[1]);
	if(!temp)
		return (1);
	map_split = ft_split(temp, '\n');
	free(temp);
	if (!map_split)
		return (ft_printf_fd(2, "Error\nSplit error.\n"));
	game_init(&game);
	if (map_check(map_split, &game))
		return (1);
	ft_printf("Map is correct!\n");
	//system("leaks so_long");
	mlx_test(&sprite, map_split);
	return (0);
}
