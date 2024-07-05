/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	step_rays(t_map *map, t_player *player, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_d.x = (player->pos.x - map->x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_d.x = (map->x + 1.0 - player->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_d.y = (player->pos.y - map->y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_d.y = (map->y + 1.0 - player->pos.y) * ray->delta.y;
	}
}

void	launch_rays(t_mlx *mlx, int x)
{
	t_player	*player;
	double		camera;

	player = &mlx->player;
	camera = 2 * x / (double)WIDTH - 1;
	mlx->ray.dir.x = player->direction.x + player->plane.x * camera;
	mlx->ray.dir.y = player->direction.y + player->plane.y * camera;
	mlx->ray.delta.x = fabs(1 / mlx->ray.dir.x);
	mlx->ray.delta.y = fabs(1 / mlx->ray.dir.y);
	mlx->map->x = (int)player->pos.x;
	mlx->map->y = (int)player->pos.y;
	step_rays(mlx->map, &mlx->player, &mlx->ray);
}

void	dda(t_mlx *mlx, int x)
{
	int		hit;
	t_map	*map;
	t_ray	*ray;

	hit = 0;
	map = mlx->map;
	ray = &mlx->ray;
	while (!hit)
	{
		if (ray->side_d.x < ray->side_d.y)
		{
			ray->side_d.x += ray->delta.x;
			map->x += ray->step.x;
			mlx->side = 0;
		}
		else
		{
			ray->side_d.y += ray->delta.y;
			map->y += ray->step.y;
			mlx->side = 1;
		}
		raycaster_hits(mlx, map, &hit);
	}
	mlx->draw = calculus(&mlx->ray, &mlx->player, \
		&mlx->dist_buffer[x], mlx->side);
}

void	reset_marked_cells(int *len, t_cell *marked_cells, char **game_map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < *len)
	{
		x = marked_cells[i].x;
		y = marked_cells[i].y;
		game_map[y][x] = '0';
		i++;
	}
	*len = 0;
}

void	ft_grua(t_mlx *mlx)
{
	int		x;

	x = 0;
	mlx->side = 0;
	reset_marked_cells(&mlx->num_marked_cells, mlx->marked_cells,
		mlx->map->game_map);
	while (x < (int)WIDTH)
	{
		launch_rays(mlx, x);
		dda(mlx, x);
		draw_line(mlx, x);
		x++;
	}
}
