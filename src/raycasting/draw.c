/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:27:35 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/07 18:02:18 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_ceiling(t_mlx *mlx, int x, int draw_s, int color)
{
	int	y;

	y = -1;
	while (++y < draw_s)
	{
		/* color = pixel_get(&mlx->sprite[4].img, x, y); */
		pixel_put(&mlx->img, x, y, color);
	}
}

void	draw_walls(t_mlx *mlx, int x, int draw_s, int draw_e)
{
	int	color;
	int	y;
	int	tex_y;
	
	y = draw_s;
	while (y < draw_e)
	{
		tex_y = (int)mlx->tex_pos & (SPRITE_SIZE - 1);
		mlx->tex_pos += mlx->scale;
	/* 	printf("index:%i\n", mlx->sprite_index);
		exit(0); */
		color = pixel_get(&mlx->sprite[mlx->sprite_index].img, mlx->tex_x, tex_y);
		pixel_put(&mlx->img, x, y, color);
		y++;
	}
}

void	draw_floor(t_image *img, int x, int draw_e, int color)
{
	int	y;

	y = draw_e;
	while (y < (int)HEIGHT)
	{
		pixel_put(img, x, y, color);
		y++;
	}
}

void	draw_texture(t_mlx *mlx, int x)
{
	int		draw_s;
	int		draw_e;
	
	draw_s = (int)HEIGHT / 2 - mlx->line_height / 2;
	draw_e = (int)HEIGHT / 2 + mlx->line_height / 2;
	if (draw_s < 0)
		draw_s = 0;
	draw_e = (int)HEIGHT / 2 + mlx->line_height / 2;
	if (draw_e >= (int)HEIGHT)
		draw_e = (int)HEIGHT;
	mlx->scale = SPRITE_SIZE / mlx->line_height;
	mlx->tex_pos = (draw_s - (int)HEIGHT / 2 + mlx->line_height / 2) * mlx->scale;
	draw_ceiling(mlx, x, draw_s, mlx->c_color);
	draw_walls(mlx, x, draw_s, draw_e);
	draw_floor(&mlx->img, x, draw_e, mlx->f_color);
}
