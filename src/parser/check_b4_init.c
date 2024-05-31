/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_b4_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:40:18 by jmarinho          #+#    #+#             */
/*   Updated: 2024/05/31 12:57:36 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_count_map_lines(t_mlx *mlx)
{
	int	fd;
	char *line;

	mlx->map.total_lines = 0;
	fd = open(mlx->file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error\nCouldn't open requested file\n", mlx);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mlx->map.total_lines++;
		free(line);
	}
	close(fd);
}

t_mlx ft_check_b4_init(int ac, char **av, t_mlx *mlx)
{
	mlx->file = av[1];
	mlx->map.config_map[5] = NULL;
	mlx->map.NO_flag = false;
	mlx->map.SO_flag = false;
	mlx->map.EA_flag = false;
	mlx->map.WE_flag = false;
	mlx->map.F_flag = false;
	mlx->map.C_flag = false;
	mlx->map.lines_to_map = 0;
	ft_count_map_lines(mlx);
	if (ac != 2)
    	ft_perror("Error\nNumber of arguments used to launch program are invalid!\n", mlx);
    ft_check_filename(mlx);
	ft_copy_config_map(mlx);
	ft_copy_game_map(mlx);
	//ft_check_game_map(mlx);
	return *mlx;
}

void	ft_perror(char *msg, t_mlx *mlx)
{
    ft_fprintf(2, "%s", msg);
	(void) mlx;
	/*if (*mlx->map.file_map)
		ft_free_dp((void**)mlx->map.file_map);
	if (*mlx->map.game_map)
		ft_free_dp((void**)mlx->map.game_map);
	//ft_free_dp((void**)mlx->map.config_map);*/
    exit (EXIT_SUCCESS);
}

int	ft_check_filename(t_mlx *mlx)
{
	char *str = mlx->file;

	if (ft_strnstr(str + ft_strlen(str) - 4, ".cub", 4))
		return (EXIT_SUCCESS);
	else
		ft_perror("Error\nInvalid file extension. Try maps/<map_name>.cub\n", mlx);
	return (0);
}
