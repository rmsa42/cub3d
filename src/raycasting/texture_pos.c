/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:22:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/10 11:40:40 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	set_sprite(t_ray *ray, int side)
{
	int	sprite_index;

	sprite_index = 0;
	if (side == 1)
	{
		if (ray->dir.y < 0)
			sprite_index = 0;
		else
			sprite_index = 1;
	}
	else if (side == 0)
	{
		if (ray->dir.x < 0)
			sprite_index = 2;
		else
			sprite_index = 3;
	}
	return (sprite_index);
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
	mlx->sprite_index = set_sprite(ray, side);
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
	mlx->tex_x = text_x(ray, mlx->side, perp_wall, mlx);
	mlx->line_height = fabs((int)HEIGHT / perp_wall);
	mlx->scale = SPRITE_SIZE / mlx->line_height;
}
