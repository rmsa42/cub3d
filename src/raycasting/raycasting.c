/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/07 16:00:55 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	step_rays(t_map map, t_player player, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_d.x = (player.pos.x - map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_d.x = (map.x + 1.0 - player.pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_d.y = (player.pos.y - map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_d.y = (map.y + 1.0 - player.pos.y) * ray->delta.y;
	}
}

void	launch_rays(t_mlx *mlx, int x)
{
	t_player	*player;

	player = &mlx->player;
	mlx->camera = 2 * x / (double)WIDTH - 1;
	mlx->ray.dir.x = player->direction.x + player->plane.x * mlx->camera;
	mlx->ray.dir.y = player->direction.y + player->plane.y * mlx->camera;
	mlx->angle = acos(1/length_vector(mlx->ray.dir));
	mlx->ray.delta.x = fabs(1 / mlx->ray.dir.x);
	mlx->ray.delta.y = fabs(1 / mlx->ray.dir.y);
	mlx->map.x = (int)player->pos.x;
	mlx->map.y = (int)player->pos.y;
	step_rays(mlx->map, mlx->player, &mlx->ray);
}


void	dda(t_mlx *mlx, t_map *map, t_ray *ray)
{
	int	hit;

	hit = 0;
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
		if (map->game_map[map->y][map->x] == '1')
			hit = 1;
	}
}

int	text_x(t_ray *ray, int side, double perp_wall, t_mlx *mlx)
{
	double	wall_x;
	int		tex_x;

	mlx->sprite_index = 0;
	wall_x = 0;
	tex_x = 0;
	if (side == 0)
		wall_x = mlx->player.pos.y + perp_wall * ray->dir.y;
	else
		wall_x = mlx->player.pos.x + perp_wall * ray->dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (int)SPRITE_SIZE);
	if ((side == 0 && ray->dir.x < 0) || (side == 1 && ray->dir.y > 0))
		tex_x = SPRITE_SIZE - tex_x - 1;
	if (side == 1)
	{
		if(ray->dir.y < 0)
			mlx->sprite_index = 0;
		else
			mlx->sprite_index = 1;
	}
	else if(side == 0)
	{
		if (ray->dir.x < 0)
			mlx->sprite_index = 2;
		else
			mlx->sprite_index = 3;
	}
	return (tex_x);
}

void	calculus(t_mlx *mlx, t_ray *ray)
{
	double	perp_wall;

	perp_wall = 0;
	if (mlx->side == 0)
		perp_wall = (ray->side_d.x - ray->delta.x);
	else
		perp_wall = (ray->side_d.y - ray->delta.y);
	// SegFault ao entrar na parede
	// printf("Perp: %f\n", perp_wall);
	/* if (perp_wall - 0.00001 < 0)
		perp_wall = 1; */
	mlx->tex_x = text_x(ray, mlx->side, perp_wall, mlx);
	mlx->line_height = fabs((int)HEIGHT / perp_wall);
}

void	ft_grua(t_mlx *mlx)
{
	int		x;

	x = 0;
	mlx->side = 0;
	while (x < (int)WIDTH)
	{
		launch_rays(mlx, x);
		dda(mlx, &mlx->map, &mlx->ray);
		calculus(mlx, &mlx->ray);
		draw_texture(mlx, x);
		x++;
	}
	image_to_window(mlx, mlx->img.img_ptr, 0, 0);
}
