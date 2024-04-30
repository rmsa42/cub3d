/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/30 17:49:47 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	foward_rays(t_mlx *mlx, t_v2D ray)
{
	double	pX;
	double	pY;
	double	s;

	s = 0;
	pX = mlx->player.pos.x;
	pY = mlx->player.pos.y;
	mlx->map.x = (int)pX;
	mlx->map.y = (int)pY;
	while (mlx->map.game_map[mlx->map.y][mlx->map.x] != '1')
	{
		pX += ray.x * s;
		pY += ray.y * s;
		mlx->map.x = (int)pX;
		mlx->map.y = (int)pY;
		s = 0.001;
	}
	mlx->ray_pos.x = pX;
	mlx->ray_pos.y = pY;
}

void	launch_rays(t_mlx *mlx, int x)
{
	t_player	*player;
	t_v2D		ray;

	player = &mlx->player;
	mlx->camera = 2 * x / (double)WIDTH - 1;
	ray.x = player->direction.x + player->plane.x * mlx->camera;
	ray.y = player->direction.y + player->plane.y * mlx->camera;
	mlx->angle = acos(1/length_vector(ray));
	foward_rays(mlx, ray);
}

void	draw_texture(t_mlx *mlx, int x, double line)
{
	int y;
	int draw_s;
	int	draw_e;
	int	color;
	
	y = -1;
	draw_s = HEIGHT / 2 - line / 2;
	draw_e = HEIGHT / 2 + line / 2;
	assert(mlx->sprite[0].img.addr != NULL);
	while (++y < draw_s)
		pixel_put(&mlx->img, x, y, mlx->c_color);
	while (y < draw_e)
	{
		color = pixel_get(&mlx->sprite[0].img, x, y);
		pixel_put(&mlx->img, x, y, color);
		y++;
	}
	while(y < HEIGHT)
	{
		pixel_put(&mlx->img, x, y, mlx->f_color);
		y++;
	}
}


void	dda(t_mlx *mlx, int x)
{
	t_player	*player;
	t_v2D		ray;
	double		length;
	double		line = 0;

	player = &mlx->player;
	ray = create_vector(mlx->ray_pos.x - player->pos.x, mlx->ray_pos.y - player->pos.y);
	length = length_vector(ray);
	length = cos(mlx->angle) * length;
	line = HEIGHT / length;
	if(line >= HEIGHT)
		line = HEIGHT- 1;
	draw_texture(mlx, x, line);
}

void	ft_grua(t_mlx *mlx)
{
	int		x;

	x = 0;
	while (x < (int)WIDTH)
	{
		launch_rays(mlx, x);
		dda(mlx, x);
		x++;
	}
	image_to_window(mlx, mlx->img.img_ptr, 0, 0);
}
