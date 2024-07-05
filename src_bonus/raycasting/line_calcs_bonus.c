/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_calcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:01:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	text_x(t_ray *ray, int side, double perp_wall, t_player *player)
{
	double	wall_x;
	int		tex_x;

	wall_x = 0;
	tex_x = 0;
	if (side == 0)
		wall_x = player->pos.y + perp_wall * ray->dir.y;
	else
		wall_x = player->pos.x + perp_wall * ray->dir.x;
	wall_x -= (int)(wall_x);
	tex_x = (int)(wall_x * (int)SPRITE_SIZE);
	if ((side == 0 && ray->dir.x < 0) || (side == 1 && ray->dir.y > 0))
		tex_x = SPRITE_SIZE - tex_x - 1;
	return (tex_x);
}

t_draw	calculus(t_ray *ray, t_player *player, double *perp_wall_dist, int side)
{
	t_draw	draw;

	if (side == 0)
		*perp_wall_dist = (ray->side_d.x - ray->delta.x);
	else
		*perp_wall_dist = (ray->side_d.y - ray->delta.y);
	draw.tex_x = text_x(ray, side, *perp_wall_dist, player);
	draw.line_height = fabs(HEIGHT / *perp_wall_dist);
	draw.start = (HEIGHT / 2 - draw.line_height / 2) + player->pitch;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = (HEIGHT / 2 + draw.line_height / 2) + player->pitch;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	draw.scale = SPRITE_SIZE / draw.line_height;
	draw.tex_pos = (draw.start - player->pitch - HEIGHT / 2 + \
			draw.line_height / 2) * draw.scale;
	return (draw);
}
