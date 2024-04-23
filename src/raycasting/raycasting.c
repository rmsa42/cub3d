/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/23 15:17:37 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate(t_player *player, int *px, int *py)
{
	float	newX;
	float	newY;
	
	newX = player->pos.x * 64 + (*px - player->pos.x * 64) * cos(player->angle) - (*py - player->pos.y * 64) * sin(player->angle);
    newY = player->pos.y * 64 + (*px - player->pos.x * 64) * sin(player->angle) + (*py - player->pos.y * 64) * cos(player->angle);

	*px = (int)newX;
	*py = (int)newY;
}

void	ft_grua(t_mlx *mlx)
{
	// t_v2D		camera;
	t_player	*player;
	t_map		*map;

	player = &mlx->player;
	map = &mlx->map;

	int cx = (player->pos.x) * 64;
	int cy = player->pos.y * 64;
	int px = (player->pos.x) * 64;
	int py = player->pos.y * 64;
	for (int i = 0; map->game_map[py/64][px/64] != '1' ; i++)
	{
		cx = (player->pos.x) * 64 + i;
		cy = player->pos.y * 64;
		px = (player->pos.x) * 64;
		py = player->pos.y * 64 - i;
		rotate(player, &cx, &cy);
		rotate(player, &px, &py);
		player->direction.x = px;
		player->direction.y = py;
		// printf("Camera: %f %f\n", camera.x /64,camera.y /64);
		// printf("Direction: %d %d\n", px /64,py /64);
		mlx_pixel_put(mlx->lib, mlx->window,
			px, py, GREEN);
		mlx_pixel_put(mlx->lib, mlx->window,
			cx, cy, GREEN);
	}
	// player->direction = divide_vector(player->direction, create_vector(64, 64));
	// player->direction = minus_vector(player->direction, player->pos);
	
	
	//  printf("Direction Pos: %f, %f\n", player->direction.x, player->direction.y); 
}
