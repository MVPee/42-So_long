/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:23:26 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/15 11:47:42 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int map_validity(char *map)
{
    int fd;

    fd = open(map, O_RDONLY);
    if(fd != 3)
        return (ft_printf_fd(2, "Error\nCannot read file.\n"));
    return 0;
}