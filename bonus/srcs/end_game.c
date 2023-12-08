/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:32:54 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/12/08 14:22:33 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end_game(t_data *data, char *message)
{
	(void)message;
	(void)data;
	if (ft_strncmp(message, "closeNotification:", ft_strlen(message)) == 0)
		ft_printf("\nCLOSE\n");
	else
		ft_printf("%s\n", message);
	ft_free_split(3, &data->map, &data->pos_monster);
	mlx_destroy_window(data->mlx, data->window);
	exit(EXIT_SUCCESS);
}
