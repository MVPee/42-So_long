/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:32 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/20 12:49:45 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int movement(t_data *data, int y, int x)
{
    int *pos = player_position(data->map);
    if (!pos)
        return 0;
    if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] + x] == '0')
    {
        data->map[pos[0]][pos[1]] = '0';
        data->map[pos[0] + y][pos[1] + x] = 'P';
    }
    if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] + x] == 'C')
    {
        data->map[pos[0]][pos[1]] = '0';
        data->map[pos[0] + y][pos[1] + x] = 'P';
        data->collected++;
    }
    if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] + x] == 'E')
    {
        if(data->collected == data->coin)
        {
            free(pos);
            exit(0);
        }
    }
    free(pos);
    return (1);
}

static int game_process(int keycode, t_data *data)
{
    if(keycode == W || keycode == UP)
        data->movement += movement(data, -1, 0);
    else if(keycode == S || keycode == DOWN)
        data->movement += movement(data, 1, 0);
    else if(keycode == A || keycode == LEFT)
        data->movement += movement(data, 0, -1);
    else if(keycode == D || keycode == RIGHT)
        data->movement += movement(data, 0, 1);
    else if(keycode == ESC)
    {
        exit(0);
    }
    map_display(data->mlx, data->window, data->data_sprite, data->map);
    ft_printf("Nb of movement: %d\n", data->movement);
    return 0;
}

static int mlx_start(t_game game, char **map_split)
{
    void    *mlx;
    void    *window;
    t_sprite	sprite;
    t_data data;

    mlx = mlx_init();
    window = mlx_new_window(mlx, ft_strlen(map_split[0]) * 100, ft_splitlen((const char **)map_split) * 100, "So long");
    sprite_init(mlx, &sprite);
    if (!sprite.coin || !sprite.wall || !sprite.ground || !sprite.player || !sprite.exit)
    {
        mlx_destroy_window(mlx, window);
        return 1;
    }
    data_init(&data, sprite, game, map_split, mlx, window);
    map_display(data.mlx, data.window, data.data_sprite, data.map);
    mlx_hook(window, 2, 1L << 0, game_process, &data);
    mlx_loop(mlx);
    return 0;
}

int	main(int ac, char **av)
{
	t_game	game;
	char	**map_split;
	char 	*temp;

	if (ac != 2)
		return (ft_printf_fd(2, "Error\nTry: ./so_long maps/map.ber\n"));
	temp = ft_read(open(av[1], O_RDONLY));
	if(!temp)
		return (1);
	map_split = ft_split(temp, '\n');
	free(temp);
	if (!map_split)
		return (ft_printf_fd(2, "Error\nSplit error.\n"));
	game_init(&game);
	if (map_check(map_split, &game) || map_path_check(ft_splitdup((const char **)map_split)))
		return (1);
	ft_printf("Map is correct!\n");
	mlx_start(game, map_split);
	return (0);
}
