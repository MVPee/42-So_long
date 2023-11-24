/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:32:54 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/24 10:27:39 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	end_game(t_data *data, char *message)
{
	int	i;

	if (ft_strncmp(message, "closeNotification:", ft_strlen(message)) == 0)
		ft_printf("\nCLOSE\n");
	else
		ft_printf("%s\n", message);
	i = 0;
	mlx_destroy_window(data->mlx, data->window);
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
	ft_free_split(data->map);
	exit(EXIT_SUCCESS);
}
