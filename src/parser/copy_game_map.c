/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:35:11 by jmarinho          #+#    #+#             */
/*   Updated: 2024/05/09 14:54:08 by jmarinho         ###   ########.fr       */
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

void    ft_check_game_map(t_mlx *mlx)
{
    int i;
    int k;

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
                ft_perror("ERROR\nInvalid characters on game map", mlx);
            if (mlx->map.game_map[0][k] != '1' || mlx->map.game_map[mlx->map.x][k] != '1')//checka se o mapa e rodeado por paredes em cima e em baixo
                ft_perror("ERROR\nMap is not surrounded by walls(1)", mlx);
            if (mlx->map.game_map[i][0] != '1' || mlx->map.game_map[i][mlx->map.y] != '1')//checka se o mapa e rodeado por paredes a esquerda e a direita
                ft_perror("ERROR\nMap is not surrounded by walls(2)", mlx);
        }
            
    }
}

int	ft_count_lines(t_mlx *mlx)
{
	int i;

	i = 0;
	while (mlx->map.file_map[i])
		i++;
	//printf("%s\n", mlx->map.file_map[i]);
	return i;
}

void	ft_copy_game_map_aux(t_mlx *mlx)
{
	char	*line;
	char	*map_join;
	int	i;
	int	fd;

	i = -1;
	map_join = NULL;
	mlx->map.file_map = malloc(sizeof(char *) * mlx->map.x);
	if (!mlx->map.file_map)
		ft_perror ("ERROR\nMalloc for mlx->map.file_map failed", mlx);
	fd = open(mlx->file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error\nCouldn't open requested file.", mlx);
	while (++i <= mlx->map.x)
	{
		line = get_next_line(fd);
		if(!line || line[0] == '\n')
			continue;
		map_join = ft_strjoin_get(map_join, line);
		free (line);
	}
	close(fd);
	mlx->map.file_map = ft_split(map_join, '\n');
	free (map_join);
	//print_map(mlx->map.file_map);
	if (!mlx->map.file_map)
		ft_perror ("ERROR\nFile_map non existing", mlx);
}

void	ft_copy_game_map(t_mlx *mlx)
{
	int cl;

	ft_copy_game_map_aux(mlx);
	cl = ft_count_lines(mlx);
	//printf("cl %i\n", cl);
	mlx->map.game_map_lines = cl - 6;
			
	//#TODO moises for game_map

	
	
}