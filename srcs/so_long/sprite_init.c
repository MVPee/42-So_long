/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:32:16 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 14:26:13 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void sprite_init(void *mlx, t_sprite *sprite)
{
    int img_height;
    int img_width;

    sprite->coin = mlx_xpm_file_to_image(mlx, "rscs/coin.xpm", &img_width, &img_height);
    sprite->wall = mlx_xpm_file_to_image(mlx, "rscs/wall.xpm", &img_width, &img_height);
    sprite->ground = mlx_xpm_file_to_image(mlx, "rscs/ground.xpm", &img_width, &img_height);
    sprite->player = mlx_xpm_file_to_image(mlx, "rscs/player.xpm", &img_width, &img_height);
    sprite->exit = mlx_xpm_file_to_image(mlx, "rscs/exit.xpm", &img_width, &img_height);
}