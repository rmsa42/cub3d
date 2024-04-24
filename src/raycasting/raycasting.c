/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/24 12:15:41 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate(t_player *player, double *px, double *py)
{
	float	newX;
	float	newY;
	
	newX = player->pos.x * 64 + (*px - player->pos.x * 64) * cos(player->angle) - (*py - player->pos.y * 64) * sin(player->angle);
    newY = player->pos.y * 64 + (*px - player->pos.x * 64) * sin(player->angle) + (*py - player->pos.y * 64) * cos(player->angle);

	*px = newX;
	*py = newY;
}

void	ft_grua(t_mlx *mlx)
{
	t_v2D		ray;
	t_v2D		camera;
	t_player	*player;
	t_map		*map;
	t_v2D		cVec;
	player = &mlx->player;
	map = &mlx->map;

	double px = (player->pos.x) * 64;
	double py = player->pos.y * 64;
	ray = create_vector(player->pos.x * 64, player->pos.y * 64);
	for (int i = 0; map->game_map[(int)ray.y/64][(int)ray.x/64] != '1' ; i++)
	{
		camera = create_vector(player->pos.x * 64 + i, player->pos.y * 64);
		px = (player->pos.x) * 64;
		py = player->pos.y * 64 - i;
		rotate(player, &camera.x, &camera.y);
		rotate(player, &px, &py);
		player->direction.x = px / 64;
		player->direction.y = py / 64;
		player->direction = minus_vector(player->direction, player->pos);
		cVec = divide_vector(camera, create_vector(64, 64));
		cVec = minus_vector(camera, player->pos);
		ray = add_vector(player->pos, add_vector(player->direction, cVec));
		
		// printf("Camera: %f %f\n", camera.x /64,camera.y /64);
		// printf("Direction: %d %d\n", px /64,py /64);
		mlx_pixel_put(mlx->lib, mlx->window,
			px, py, GREEN);
		mlx_pixel_put(mlx->lib, mlx->window,
			camera.x, camera.y, GREEN);
		mlx_pixel_put(mlx->lib, mlx->window,
			ray.x, ray.y, GREEN);
	}
	
	//  printf("Direction Pos: %f, %f\n", player->direction.x, player->direction.y); 
}
