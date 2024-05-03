/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/02 17:34:43by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_v2D	foward_rays(t_mlx *mlx, t_ray *ray)
{
	t_v2D	step;
	t_map	map;

	map = mlx->map;
	map.x = (int)mlx->player.pos.x;
	map.y = (int)mlx->player.pos.y;
	step = create_vector(0, 0);
	if (ray->pos.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray->pos.y < 0)
		step.y = -1;
	else
		step.y = 1;
	ray->side_x = (1 - (mlx->player.pos.x - map.x)) / sin(mlx->angle);
	ray->side_y = (mlx->player.pos.y - map.y) / cos(mlx->angle);
	/* printf("sx: %f, sy: %f\n", ray->side_x, ray->side_y); */
	return (step);	
}

t_v2D	launch_rays(t_mlx *mlx, int x)
{
	t_player	*player;
	t_ray		ray;

	player = &mlx->player;
	mlx->camera = 2 * x / (double)WIDTH - 1;
	ray.pos.x = player->direction.x + player->plane.x * mlx->camera;
	ray.pos.y = player->direction.y + player->plane.y * mlx->camera;
	mlx->angle = acos(1/length_vector(ray.pos));
	if (mlx->angle != PI / 2)
		ray.delta_x = fabs(1 / sin(mlx->angle));
	ray.delta_y = fabs(1 / cos(mlx->angle));
	/* printf("dx: %f, dy: %f\n", ray.delta_x, ray.delta_y); */
	mlx->ray = ray; 
	return (foward_rays(mlx, &ray));
}

void	draw_texture(t_mlx *mlx, int x, double line)
{
	int y;
	int draw_s;
	int	draw_e;
	
	y = -1;
	draw_s = HEIGHT / 2 - line / 2;
	if (draw_s < 0)
		draw_s = 0;
	draw_e = HEIGHT / 2 + line / 2;
	if (draw_e >= HEIGHT)
		draw_e = HEIGHT - 1;
	while (++y < draw_s)
		pixel_put(&mlx->img, x, y, mlx->c_color);
	while (y < draw_e)
	{
/* 		color = pixel_get(&mlx->sprite[0].img, tex_x, y/(HEIGHT/SPRITE_PIXEL)); */
		pixel_put(&mlx->img, x, y, GREEN);
		y++;
	}
	while(y < HEIGHT)
	{
		pixel_put(&mlx->img, x, y, mlx->f_color);
		y++;
	}
}

void	dda(t_mlx *mlx, int x, t_v2D step)
{
	int		wall_hit;
	t_ray	*ray;
	int		side;
	double	line_height;

	line_height = 0;
	mlx->map.x = mlx->player.pos.x;
	mlx->map.y = mlx->player.pos.y;
	printf("mx: %d, my: %d\n", mlx->map.x, mlx->map.y);
	ray = &mlx->ray;
	wall_hit = 0;
	while (!wall_hit)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			mlx->map.x += step.x;
			side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			mlx->map.y += step.y;
			side = 1;
		}
		if (mlx->map.game_map[mlx->map.y][mlx->map.x] == '1')
		{
			printf("mx: %d, my: %d\n", mlx->map.x, mlx->map.y);
			wall_hit = 1;
		}
	}
	if (side == 1)
		line_height = HEIGHT / (ray->side_y - ray->delta_y); 
	else
		line_height = HEIGHT / (ray->side_x - ray->delta_x);
	printf("Line: %f, %f\n", ray->side_x, ray->side_y);
	/* exit(0); */
	draw_texture(mlx, x, line_height);
}

void	ft_grua(t_mlx *mlx)
{
	int		x;
	t_v2D	step;

	x = 0;
	while (x < (int)WIDTH)
	{
		step = launch_rays(mlx, x);
		dda(mlx, x, step);
		x++;
	}
	image_to_window(mlx, mlx->img.img_ptr, 0, 0);
}
