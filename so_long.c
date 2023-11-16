/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:32 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/16 11:06:36 by mvan-pee         ###   ########.fr       */
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

int mlx_test(void)
{
    void    *mlx;
    void    *window;
    void    *image;
    int     img_width, img_height;

    // Initialisation de MLX
    mlx = mlx_init();

    // Création d'une fenêtre
    window = mlx_new_window(mlx, 800, 600, "So long");

    // Chargement de l'image XPM
    image = mlx_xpm_file_to_image(mlx, "rscs/coin.xpm", &img_width, &img_height);

    // Vérifier si l'image a été chargée correctement
    if (!image)
    {
        mlx_destroy_window(mlx, window);
        return 1;
    }

    // Affichage de l'image dans la fenêtre
	mlx_put_image_to_window(mlx, window, image, 0, 0); // 0, 0 sont les coordonnées x, y
    mlx_put_image_to_window(mlx, window, image, 0, 100); // 0, 0 sont les coordonnées x, y
	mlx_put_image_to_window(mlx, window, image, 100, 100); // 0, 0 sont les coordonnées x, y

    // Démarrage de la boucle d'événements MLX
    mlx_loop(mlx);

    return 0;
}

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
	mlx_test();
	return (0);
}
