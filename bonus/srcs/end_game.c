/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:32:54 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/06 15:45:15 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end_game(t_data *data, char *message)
{
	if (ft_strncmp(message, "closeNotification:", ft_strlen(message)) == 0)
		ft_printf("\nCLOSE\n");
	else
		ft_printf("%s\n", message);
	if (data->data_sprite.player)
		mlx_destroy_image(data->mlx, data->data_sprite.player);
	if (data->data_sprite.ground)
		mlx_destroy_image(data->mlx, data->data_sprite.ground);
	if (data->data_sprite.coin_current)
		mlx_destroy_image(data->mlx, data->data_sprite.coin_current);
	if (data->data_sprite.wall)
		mlx_destroy_image(data->mlx, data->data_sprite.wall);
	if (data->data_sprite.exit_open)
		mlx_destroy_image(data->mlx, data->data_sprite.exit_open);
	if (data->data_sprite.exit_close)
		mlx_destroy_image(data->mlx, data->data_sprite.exit_close);
	if (data->data_sprite.monster_current)
		mlx_destroy_image(data->mlx, data->data_sprite.monster_current);
	ft_free_split((char **)data->map);
	ft_free_split((int **)data->pos_monster);
	mlx_destroy_window(data->mlx, data->window);
	exit(EXIT_SUCCESS);
}
