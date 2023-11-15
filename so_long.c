/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:32 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/15 11:46:56 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		return (ft_printf_fd(2, "Error\nTry: ./so_long maps/map.ber\n"));
	}
	if (map_validity(av[1]))
		return (1);
	return (0);
}
