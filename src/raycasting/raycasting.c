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

void	foward_rays(t_mlx *mlx, t_ray ray)
{
	int	wall_hit;

	wall_hit = 0;
	while (wall_hit)
	{

	}
}

void	launch_rays(t_mlx *mlx, int x)
{
	t_player	*player;
	t_ray		ray;

	player = &mlx->player;
	mlx->camera = 2 * x / (double)WIDTH - 1;
	ray.pos.x = player->direction.x + player->plane.x * mlx->camera;
	ray.pos.y = player->direction.y + player->plane.y * mlx->camera;
	mlx->angle = acos(1/length_vector(ray.pos));
	ray.delta_x = 1 / sin(mlx->angle);
	ray.delta_y = 1 / cos(mlx->angle);
	ray.side_x = ray.delta_x / 2;
	ray.side_y = ray.delta_y / 2; 
	foward_rays(mlx, ray);
}

void	draw_texture(t_mlx *mlx, int x, double line, double teste)
{
	int y;
	int draw_s;
	int	draw_e;
	int	color;
	int	tex_x;
	
	y = -1;
	draw_s = HEIGHT / 2 - line / 2;
	draw_e = HEIGHT / 2 + line / 2;
	assert(mlx->sprite[0].img.addr != NULL);
	
	tex_x = teste * x;
	tex_x = tex_x/(WIDTH/SPRITE_PIXEL);

	while (++y < draw_s)
		pixel_put(&mlx->img, x, y, mlx->c_color);
	while (y < draw_e)
	{
		color = pixel_get(&mlx->sprite[0].img, tex_x, y/(HEIGHT/SPRITE_PIXEL));
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
	double		teste;

	player = &mlx->player;
	ray = create_vector(mlx->ray_pos.x - player->pos.x, mlx->ray_pos.y - player->pos.y);
	length = length_vector(ray);
	length = cos(mlx->angle) * length;
	line = HEIGHT / length;
	teste = sin(mlx->angle);
	if(line >= HEIGHT)
		line = HEIGHT- 1;
	draw_texture(mlx, x, line, teste);
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
