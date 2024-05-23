/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:27:25 by jmarinho          #+#    #+#             */
/*   Updated: 2024/05/23 11:39:38 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    ft_get_game_map_rows(t_mlx *mlx)
{
    int i;

    i = -1;
    mlx->map.x = -1;
    if (!mlx->map.game_map)
        return ;
    while (mlx->map.game_map[++i])
        mlx->map.x++;
}

void    ft_get_game_map_cols(t_mlx *mlx)
{
    int i;

    i = -1;
    mlx->map.y = -1;
    if (!mlx->map.game_map[0])
        return ;
    while (mlx->map.game_map[0][++i])
        mlx->map.y++;
}

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

void    ft_check_game_map(t_mlx *mlx)
{
    int i;
    int k;

    #//TODO fazer checkagens ao mapa

    i = -1;
    ft_get_game_map_rows(mlx);
    ft_get_game_map_cols(mlx);
    while (mlx->map.game_map[++i])
    {
        k = -1;
        while (mlx->map.game_map[i][++k])
        {
            if (mlx->map.game_map[i][k] != '0' && mlx->map.game_map[i][k] != '1' && mlx->map.game_map[i][k] != 'N' 
                && mlx->map.game_map[i][k] != 'S' && mlx->map.game_map[i][k] != 'E' && mlx->map.game_map[i][k] != 'W')
                ft_perror("ERROR\nInvalid characters on game map\n", mlx);
            if (mlx->map.game_map[0][k] != '1' || mlx->map.game_map[mlx->map.x][k] != '1')//checka se o mapa e rodeado por paredes em cima e em baixo
                ft_perror("ERROR\nMap is not surrounded by walls(1)\n", mlx);
            if (mlx->map.game_map[i][0] != '1' || mlx->map.game_map[i][mlx->map.y] != '1')//checka se o mapa e rodeado por paredes a esquerda e a direita
                ft_perror("ERROR\nMap is not surrounded by walls(2)\n", mlx);
        }
            
    }
}
