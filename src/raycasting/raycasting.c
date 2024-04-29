/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/29 16:46:28 by rumachad         ###   ########.fr       */
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
		s += 0.001;
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
	foward_rays(mlx, ray);
}

void	dda(t_mlx *mlx, int x)
{
	t_player	*player;
	t_v2D		ray;
	double		length;
	double		line = 0;
	int			y = 0;

	player = &mlx->player;
	/* print_vector(player->pos);
	printf("Ray: %f, %f\n", mlx->ray_pos.x, mlx->ray_pos.y); */
	ray = create_vector(mlx->ray_pos.x - player->pos.x, mlx->ray_pos.y - player->pos.y);
	length = length_vector(ray);
	/* printf("%f\n ", length); */
	// printf("len:%f\n", length);
	line = HEIGHT / length;
	if(line >= HEIGHT)
		line = HEIGHT- 1;
	int drawY = HEIGHT / 2 - line / 2;
	while (y < line)
	{
		pixel_put(&mlx->img, x, drawY + y);
		// printf("%d\n", drawY);
		y++;
	}
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
