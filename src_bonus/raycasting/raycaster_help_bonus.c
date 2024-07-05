/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_help_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:20 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	raycaster_hits(t_mlx *mlx, t_map *map, int *hit)
{
	if (map->game_map[map->y][map->x] == '0')
	{
		mlx->marked_cells[mlx->num_marked_cells++] = (t_cell){map->x, \
			map->y};
		map->game_map[map->y][map->x] = 'X';
	}
	else if (map->game_map[map->y][map->x] == '1')
	{
		*hit = 1;
		mlx->spr_index = select_sprite(&mlx->ray, mlx->side);
	}
	else if (map->game_map[map->y][map->x] == 'D' || \
		map->game_map[map->y][map->x] == 'd'
		|| map->game_map[map->y][map->x] == 'P' || \
			map->game_map[map->y][map->x] == 'p')
	{
		*hit = 1;
		door_hit(mlx, map);
	}
}
