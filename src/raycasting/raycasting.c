/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/24 17:53:24 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	see(t_mlx *mlx, t_v2D ray)
{
	t_map	*map;
	double	pX;
	double	pY;
	
	pX = mlx->player.pos.x;
	pY = mlx->player.pos.y;
	map = &mlx->map;
	map->x = (int)pX;
	map->y = (int)pY;
	while (map->game_map[map->y][map->x] != '1')
	{
		
	}
}

void	ft_grua(t_mlx *mlx)
{
	t_player	*player;
	t_v2D		ray;
	double		camera;
	int			x;

	x = 0;
	player = &mlx->player;
	while (x < (int)WIDTH)
	{
		camera = 2 * x / (double)WIDTH - 1;
		ray.x = player->direction.x + player->plane.x * -camera;
		ray.y = player->direction.y + player->plane.y * -camera;
		see(mlx, ray);
		x++;
	}
	exit(0);
}
