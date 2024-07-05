/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:42:31 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/05 13:24:14 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_v2D	sprite_dist(t_player *player, t_v2D pos)
{
	t_v2D	spr_vector;
	t_v2D	transform;
	double	inv;

	spr_vector.x = pos.x - player->pos.x;
	spr_vector.y = pos.y - player->pos.y;
	inv = 1 / (player->plane.x * player->direction.y
			- player->plane.y * player->direction.x);
	transform.x = inv * (player->direction.y * spr_vector.x
			- player->direction.x * spr_vector.y);
	transform.y = inv * (-player->plane.y * spr_vector.x
			+ player->plane.x * spr_vector.y);
	return (transform);
}

t_draw_sprite	draw_start_calc(t_v2D s_dist, int pitch)
{
	t_draw_sprite	draw;

	draw.screen_x = (int)(WIDTH / 2)*(1 + s_dist.x / s_dist.y);
	draw.height = abs((int)(HEIGHT / s_dist.y));
	draw.start_y = (-draw.height / 2 + HEIGHT / 2) + pitch;
	if (draw.start_y < 0)
		draw.start_y = 0;
	draw.end_y = (draw.height / 2 + HEIGHT / 2) + pitch;
	if (draw.end_y >= HEIGHT)
		draw.end_y = HEIGHT;
	draw.start_x = -draw.height / 2 + draw.screen_x;
	if (draw.start_x < 0)
		draw.start_x = 0;
	draw.end_x = draw.height / 2 + draw.screen_x;
	if (draw.end_x >= WIDTH)
		draw.end_x = WIDTH;
	return (draw);
}

void	draw_sprite_line(t_mlx *mlx, t_image *sprite, t_draw_sprite draw, int x)
{
	int	y;
	int	d;
	int	color;

	color = 0;
	y = draw.start_y;
	while (y < draw.end_y)
	{
		d = y * 64 - HEIGHT * 32 + draw.height
			* 32 - mlx->player.pitch * 64;
		draw.tex_y = ((d * SPRITE_SIZE) / draw.height) / 64;
		if (draw.tex_y >= 0 && draw.tex_y < SPRITE_SIZE)
		{
			color = pixel_get(sprite, draw.tex_x, draw.tex_y);
			if (color != TRANSPARENT)
				pixel_put(&mlx->img, x, y, color);
		}
		y++;
	}
}

void	draw_sprite(t_v2D transform, t_mlx *mlx,
		t_image *sprite, t_draw_sprite draw)
{
	int	x;

	x = draw.start_x;
	while (x < draw.end_x)
	{
		draw.tex_x = (64 * (x - (-draw.height / 2 + draw.screen_x))
				* SPRITE_SIZE / draw.height) / 64;
		if (transform.y > 0 && x > 0 && x < WIDTH
			&& transform.y < mlx->dist_buffer[x])
			draw_sprite_line(mlx, sprite, draw, x);
		x++;
	}
}

void	draw_sprites(t_mlx *mlx)
{
	t_v2D	s_dist;
	t_objs	*obj;
	t_list	*objs_lst;

	s_dist = (t_v2D){0, 0};
	mlx->objs_lst = sort_sprites(&mlx->player, mlx->objs_lst);
	objs_lst = mlx->objs_lst;
	while (objs_lst != NULL)
	{
		obj = (t_objs *)objs_lst->content;
		s_dist = sprite_dist(&mlx->player, obj->pos);
		update_time(&mlx->current_time);
		obj->elapsed_time = time_passed(&obj->last_time, &mlx->current_time);
		draw_sprite(s_dist, mlx, &mlx->sprite[obj->spr_index].img,
			draw_start_calc(s_dist, mlx->player.pitch));
		objs_lst = objs_lst->next;
	}
}
