/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:15:49 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/12 13:42:38 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	select_sprite(t_ray *ray, int side)
{
	int	sprite_index;

	sprite_index = 0;
	if (side == 1)
	{
		if (ray->dir.y > 0)
			sprite_index = NO;
		else
			sprite_index = SO;
	}
	else if (side == 0)
	{
		if (ray->dir.x > 0)
			sprite_index = EA;
		else
			sprite_index = WE;
	}
	return (sprite_index);
}

void	door_anim(t_mlx *mlx, t_map *map)
{
	static int	i = OPEN_DOOR1;

	mlx->spr_index = DOOR1;
	if (map->game_map[map->y][map->x] == 'P' || \
		map->game_map[map->y][map->x] == 'p')
	{
		mlx->spr_index = END_DOOR1;
		if (map->game_map[map->y][map->x] == 'p')
			mlx->spr_index = END_DOOR3;
		else if (mlx->player.coins == 4)
			mlx->spr_index = END_DOOR2;
	}
	if (map->game_map[map->y][map->x] == 'd')
	{
		mlx->spr_index = i;
		if (mlx->elapsed_door >= 0.20)
		{
			i++;
			update_time(&mlx->door_time);
		}
	}
	if (i == BALL1)
		i = OPEN_DOOR1;
}

void	door_hit(t_mlx *mlx, t_map	*map)
{
	door_anim(mlx, map);
	if (mlx->side == 0)
	{
		mlx->ray.side_d.x -= mlx->ray.delta.x / 2;
		if (mlx->ray.side_d.x > mlx->ray.side_d.y)
		{
			mlx->ray.side_d.y += mlx->ray.delta.y;
			mlx->side = 1;
			mlx->spr_index = select_sprite(&mlx->ray, mlx->side);
		}
		mlx->ray.side_d.x += mlx->ray.delta.x;
	}
	else
	{
		mlx->ray.side_d.y -= mlx->ray.delta.y / 2;
		if (mlx->ray.side_d.y > mlx->ray.side_d.x)
		{
			mlx->ray.side_d.x += mlx->ray.delta.x;
			mlx->side = 0;
			mlx->spr_index = select_sprite(&mlx->ray, mlx->side);
		}
		mlx->ray.side_d.y += mlx->ray.delta.y;
	}
}
