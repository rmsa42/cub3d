/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:20:48 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/29 15:05:03 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_map(t_mlx *mlx, char tile, int x, int y)
{
	static int	p;
	/* printf("Tile : %c\n", tile); */
	/* if (tile == '1')
		image_to_window(mlx, mlx->sprite[0].img_ptr, x, y); */
	if ((tile == 'N' || tile == 'S' || tile == 'W' || tile == 'E') && (p == 0))
	{
		p++;
		mlx->player.pos.x = x + 0.5;
		mlx->player.pos.y = y + 0.5;
	}
}

void	map_draw(t_mlx *mlx)
{
	t_map	*map;

	map = &mlx->map;
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
