/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:32 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/20 15:33:38 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int end_game(t_data *data, char *message)
{
    int i;

    ft_printf("%s\n", message);
    i = 0;
    mlx_destroy_window(data->mlx, data->window);
    if(data->data_sprite.player)
        mlx_destroy_image(data->mlx, data->data_sprite.player);
    if(data->data_sprite.ground)
        mlx_destroy_image(data->mlx, data->data_sprite.ground);
    if(data->data_sprite.coin)
        mlx_destroy_image(data->mlx, data->data_sprite.coin);
    if(data->data_sprite.wall)
        mlx_destroy_image(data->mlx, data->data_sprite.wall);
    if(data->data_sprite.exit)
        mlx_destroy_image(data->mlx, data->data_sprite.exit);
    while(data->map[i])
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    exit(EXIT_SUCCESS);
}

static int movement(t_data *data, int y, int x)
{
    int *pos = player_position(data->map);
    if (!pos)
        end_game(data, "Error\nWhere is Player?");
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
            end_game(data, "\nSUCCES");
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
        end_game(data, "\nESC");
    }
    if(data->movement)
    {
        map_display(data->mlx, data->window, data->data_sprite, data->map);
        ft_printf("Step(s): %d\n", data->movement);
    }
    return (0);
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
        return (ft_printf_fd(2, "Error\nSprites fail.\n"));
    }
    data_init(&data, sprite, game, map_split, mlx, window);
    map_display(data.mlx, data.window, data.data_sprite, data.map);
    mlx_hook(window, 2, 1L << 0, game_process, &data);
    mlx_hook(window, 17, 1L << 2, end_game, &data);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, window);
    return (0);
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
	if(mlx_start(game, map_split))
        return (1);
	return (0);
}
