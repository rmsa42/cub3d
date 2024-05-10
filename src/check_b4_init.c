/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_b4_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:40:18 by jmarinho          #+#    #+#             */
/*   Updated: 2024/05/09 11:48:43 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_mlx	ft_check_b4_init(int ac, char **av, t_mlx *mlx)
{
	if (ac != 2)
		ft_perror("Error\nNumber of arguments used to launch program are \
				invalid!", NULL);
	ft_check_filename(av[1]);
	ft_read_file_and_copy_map(av[1], mlx);
	return (*mlx);
}

int	ft_perror(char *msg, t_mlx *mlx)
{
	printf("%s", msg);
	if (mlx == NULL)
		exit (EXIT_FAILURE);
	else if (mlx->map.game_map)
		exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	ft_check_filename(char *str)
{
	if (ft_strnstr(str + ft_strlen(str) - 4, ".cub", 4))
		return (EXIT_SUCCESS);
	else
	{
		printf("Error\nInvalid file extension. Try maps/<map_name>.cub");
		exit (EXIT_FAILURE);
	}
}
