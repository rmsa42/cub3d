/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:20:48 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/03 00:25:57 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_map(t_mlx *mlx, char tile, int x, int y)
{
	if ((tile == 'N' || tile == 'S' || tile == 'W' || tile == 'E'))
		mlx->player = init_player(x + 0.5, y + 0.5, tile);
}

void	map_draw(t_mlx *mlx)
{
	t_map	*map;
	int i = 0;

	map = &mlx->map;
	while (i < 6)
	{
		map->game_map++;
		i++;
	}
	map->y = 0;
	while (map->game_map[map->y])
	{
		map->x = 0;
		while (map->game_map[map->y][map->x])
		{
			draw_map(mlx, map->game_map[map->y][map->x], map->x, map->y);
			map->x++;
		}
		map->y++;
	}
}
