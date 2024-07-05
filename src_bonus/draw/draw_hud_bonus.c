/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:27:02 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:49:28 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_hud(t_image *img, t_sprite *sprite, t_v2D sprite_pos)
{
	t_v2D	scr;
	t_cell	texture;
	int		color;
	int		new_size;

	scr.y = sprite_pos.y;
	new_size = (int)(SPRITE_SIZE * 2)*((double)WIDTH / 800);
	while (++scr.y < sprite_pos.y + new_size)
	{
		scr.x = sprite_pos.x;
		texture.y = ((scr.y - (sprite_pos.y)) / 2) * (600 / (double)HEIGHT);
		while (++scr.x < sprite_pos.x + new_size)
		{
			texture.x = ((scr.x - sprite_pos.x) / 2) * (800 / (double)WIDTH);
			if (texture.x >= 0 && texture.x < SPRITE_SIZE && \
				texture.y >= 0 && texture.y < SPRITE_SIZE)
			{
				color = pixel_get(&sprite->img, \
					texture.x, texture.y);
				if (color != TRANSPARENT)
					pixel_put(img, scr.x, scr.y, color);
			}
		}
	}
}

int	custom_color(t_image *img, int pixel_x, int pixel_y, int color)
{
	unsigned int	dst_color;
	int				red;
	int				green;
	int				blue;

	dst_color = pixel_get(img, pixel_x, pixel_y);
	red = (int)(((color >> 16) & 0xFF) * 0.3 + \
		((dst_color >> 16) & 0xFF) * 0.7);
	green = (int)(((color >> 8) & 0xFF) * 0.3 + \
		((dst_color >> 8) & 0xFF) * 0.7);
	blue = (int)((color & 0xFF) * 0.3 + \
		(dst_color & 0xFF) * 0.7);
	dst_color = (color & 0xFF000000) | (red << 16) | (green << 8) | blue;
	return (dst_color);
}

void	draw_damage_heal(t_image *img, int status)
{
	t_cell	start;
	int		color;

	start.y = -1;
	while (++start.y < HEIGHT)
	{
		start.x = -1;
		while (++start.x < WIDTH)
		{
			color = custom_color(img, start.x, start.y, status);
			pixel_put(img, start.x, start.y, color);
		}
	}
}

void	draw_screen(t_image *img, t_sprite *sprite)
{
	t_v2D	scr;
	t_v2D	texture;
	int		color;

	scr.y = -1;
	while (++scr.y < HEIGHT)
	{
		scr.x = -1;
		texture.y = (scr.y) * ((double)600 / HEIGHT);
		while (++scr.x < WIDTH)
		{
			texture.x = (scr.x) * ((double)800 / WIDTH);
			color = pixel_get(&sprite->img, \
				texture.x, texture.y);
			if (color != TRANSPARENT)
				pixel_put(img, scr.x, scr.y, color);
		}
	}
}

void	draw_status(t_mlx *mlx)
{
	if (mlx->player.damaged)
	{
		draw_damage_heal(&mlx->img, DAMAGE_RED);
		if (mlx->elapsed_time >= 0.10)
			mlx->player.damaged = 0;
	}
	if (mlx->player.healed)
	{
		draw_damage_heal(&mlx->img, HEAL_GREEN);
		if (mlx->elapsed_time >= 0.10)
			mlx->player.healed = 0;
	}
}
