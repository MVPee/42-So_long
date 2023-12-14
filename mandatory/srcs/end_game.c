/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:32:54 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/14 17:00:06 by mvpee            ###   ########.fr       */
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
	if (data->data_sprite.coin)
		mlx_destroy_image(data->mlx, data->data_sprite.coin);
	if (data->data_sprite.wall)
		mlx_destroy_image(data->mlx, data->data_sprite.wall);
	if (data->data_sprite.exit)
		mlx_destroy_image(data->mlx, data->data_sprite.exit);
	mlx_destroy_window(data->mlx, data->window);
	ft_free_matrix(1, &data->map);
	ft_free(1, data->mlx);
	exit(EXIT_SUCCESS);
}
