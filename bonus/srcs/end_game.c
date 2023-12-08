/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:32:54 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/08 22:42:42 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_coin(t_data *data)
{
	if (data->data_sprite.coin1)
		mlx_destroy_image(data->mlx, data->data_sprite.coin1);
	if (data->data_sprite.coin2)
		mlx_destroy_image(data->mlx, data->data_sprite.coin2);
	if (data->data_sprite.coin3)
		mlx_destroy_image(data->mlx, data->data_sprite.coin3);
	if (data->data_sprite.coin4)
		mlx_destroy_image(data->mlx, data->data_sprite.coin4);
	if (data->data_sprite.coin5)
		mlx_destroy_image(data->mlx, data->data_sprite.coin5);
}

static void	destroy_monster(t_data *data)
{
	if (data->data_sprite.monster1)
		mlx_destroy_image(data->mlx, data->data_sprite.monster1);
	if (data->data_sprite.monster2)
		mlx_destroy_image(data->mlx, data->data_sprite.monster2);
	if (data->data_sprite.monster3)
		mlx_destroy_image(data->mlx, data->data_sprite.monster3);
	if (data->data_sprite.monster4)
		mlx_destroy_image(data->mlx, data->data_sprite.monster4);
	if (data->data_sprite.monster5)
		mlx_destroy_image(data->mlx, data->data_sprite.monster5);
	if (data->data_sprite.monster6)
		mlx_destroy_image(data->mlx, data->data_sprite.monster6);
	if (data->data_sprite.monster7)
		mlx_destroy_image(data->mlx, data->data_sprite.monster7);
	if (data->data_sprite.monster8)
		mlx_destroy_image(data->mlx, data->data_sprite.monster8);
	if (data->data_sprite.monster9)
		mlx_destroy_image(data->mlx, data->data_sprite.monster9);
}

static void	destroy_boom(t_data *data)
{
	if (data->data_sprite.boom1)
		mlx_destroy_image(data->mlx, data->data_sprite.boom1);
	if (data->data_sprite.boom2)
		mlx_destroy_image(data->mlx, data->data_sprite.boom2);
	if (data->data_sprite.boom3)
		mlx_destroy_image(data->mlx, data->data_sprite.boom3);
	if (data->data_sprite.boom4)
		mlx_destroy_image(data->mlx, data->data_sprite.boom4);
	if (data->data_sprite.boom5)
		mlx_destroy_image(data->mlx, data->data_sprite.boom5);
}

int	end_game(t_data *data, char *message)
{
	if (data->data_sprite.player)
		mlx_destroy_image(data->mlx, data->data_sprite.player);
	if (data->data_sprite.ground)
		mlx_destroy_image(data->mlx, data->data_sprite.ground);
	if (data->data_sprite.wall)
		mlx_destroy_image(data->mlx, data->data_sprite.wall);
	if (data->data_sprite.exit_open)
		mlx_destroy_image(data->mlx, data->data_sprite.exit_open);
	if (data->data_sprite.exit_close)
		mlx_destroy_image(data->mlx, data->data_sprite.exit_close);
	destroy_monster(data);
	destroy_boom(data);
	destroy_coin(data);
	mlx_destroy_window(data->mlx, data->window);
	ft_free(1, &data->mlx);
	ft_free_split(2, &data->map, &data->pos_monster);
	if (ft_strncmp(message, "closeNotification:", ft_strlen(message)) == 0)
		ft_printf("\nCLOSE\n");
	else
		ft_printf("%s\n", message);
	exit(EXIT_SUCCESS);
}
