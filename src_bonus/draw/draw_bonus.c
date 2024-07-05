/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:27:35 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:49:21 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_ceiling(t_image *img, t_draw *draw, int color, int x)
{
	int	y;

	y = -1;
	while (++y < draw->start)
		pixel_put(img, x, y, color);
}

int	darken_color(int color, int factor)
{
	int	r;
	int	g;
	int	b;

	factor /= 6;
	if (factor < 1)
		return (color);
	r = (color >> 16) / factor;
	g = (color >> 8 & 0xFF) / factor;
	b = (color & 0xFF) / factor;
	return (r << 16 | g << 8 | b);
}

void	draw_walls(t_mlx *mlx, t_draw *draw, t_sprite *sprite, int x)
{
	int	color;
	int	y;
	int	tex_y;

	y = draw->start;
	while (y < draw->end)
	{
		tex_y = (int)draw->tex_pos & (SPRITE_SIZE - 1);
		draw->tex_pos += draw->scale;
		color = pixel_get(&sprite->img, draw->tex_x, tex_y);
		color = darken_color(color, mlx->dist_buffer[x]);
		pixel_put(&mlx->img, x, y, color);
		y++;
	}
}

void	draw_floor(t_image *img, t_draw *draw, int color, int x)
{
	int	y;

	y = draw->end;
	while (y < (int)HEIGHT)
	{
		pixel_put(img, x, y, color);
		y++;
	}
}

void	draw_line(t_mlx *mlx, int x)
{
	draw_ceiling(&mlx->img, &mlx->draw, mlx->c_color, x);
	draw_walls(mlx, &mlx->draw, &mlx->sprite[mlx->spr_index], x);
	draw_floor(&mlx->img, &mlx->draw, mlx->f_color, x);
}
