/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:32 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 10:37:34 by mvan-pee         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_map	map;
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
	map_init(&map);
	if (map_check(map_split, &map))
		return (1);
	ft_printf("Map is correct!\n");
	//system("leaks so_long");
	return (0);
}
