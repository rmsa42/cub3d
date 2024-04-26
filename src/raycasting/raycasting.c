/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/26 17:17:46 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_rays(t_mlx *mlx, t_v2D ray)
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
		pixel_put(&mlx->img, pX * SPRITE_PIXEL, pY * SPRITE_PIXEL);
		pX += ray.x * s;
		pY += ray.y * s;
		mlx->map.x = (int)pX;
		mlx->map.y = (int)pY;
		s += 0.001;
	}
}

void	launch_rays(t_mlx *mlx, int x)
{
	t_player	*player;
	double		camera;
	t_v2D		ray;

	player = &mlx->player;
	camera = 2 * x / (double)WIDTH - 1;
	ray.x = player->direction.x + player->plane.x * -camera;
	ray.y = player->direction.y + player->plane.y * -camera;
	render_rays(mlx, ray);
}

void	ft_grua(t_mlx *mlx)
{
	int	x;

	x = 0;
	while (x < (int)WIDTH)
	{
		launch_rays(mlx, x);
		x++;
	}
	image_to_window(mlx, mlx->img.img_ptr, 0, 0);
}
