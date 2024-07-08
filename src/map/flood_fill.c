/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:54:02 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 12:20:34 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	flood_fill(t_mlx *mlx, t_map *map, char **flood_map, t_cell coor)
{
	if (coor.x < 0 || coor.y < 0 || coor.x >= (int)ft_strlen(flood_map[coor.y])
		|| coor.y > map->height)
	{
		ft_free_dp((void **)flood_map);
		print_error("Invalid Map(Not Wall Closed)\n", EXIT_FAILURE, mlx);
	}
	if (flood_map[coor.y][coor.x] == '1')
		return (1);
	flood_map[coor.y][coor.x] = '1';
	flood_fill(mlx, map, flood_map, (t_cell){coor.x + 1, coor.y});
	flood_fill(mlx, map, flood_map, (t_cell){coor.x - 1, coor.y});
	flood_fill(mlx, map, flood_map, (t_cell){coor.x, coor.y + 1});
	flood_fill(mlx, map, flood_map, (t_cell){coor.x, coor.y - 1});
	return (0);
}

int	call_flood_fill(t_mlx *mlx, t_map *map)
{
	t_cell	coor;
	char	**flood_map;
	int		i;
	int		len;
	char	*pl;

	i = -1;
	len = 0;
	flood_map = malloc(sizeof(char *) * (map->height + 1));
	if (flood_map == NULL)
		return (1);
	while (map->game_map[++i])
	{
		flood_map[i] = ft_strdup(map->game_map[i]);
		len = ft_strlen(flood_map[i]);
		pl = begining_of_map(flood_map[i], "NEWS");
		if (pl)
			coor = (t_cell){len - ft_strlen(pl), i};
	}
	flood_map[i] = 0;
	flood_fill(mlx, map, flood_map, coor);
	ft_free_dp((void **)flood_map);
	return (0);
}
