/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:38:32 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	update_sprite_anim(t_objs *obj, int flag)
{
	float	time;

	if (flag)
		time = 0.50;
	else
		time = 0.20;
	if (obj->spr_index == ENEMY_DOWN)
		obj->spr_index = ENEMY1;
	else if (flag && obj->elapsed_time >= time)
	{
		obj->spr_index = ENEMY1 + (obj->spr_index == ENEMY1);
		update_time(&obj->last_time);
	}
	else if (obj->elapsed_time >= time)
	{
		obj->spr_index++;
		update_time(&obj->last_time);
	}
}

void	sprite_move(t_player *player, t_objs *obj, double speed)
{
	t_v2D	dir;
	t_v2D	dist;
	t_v2D	check;

	dir.x = player->pos.x - obj->pos.x;
	dir.y = player->pos.y - obj->pos.y;
	dir = normalize_vector(dir);
	check = dir;
	dist = multiply_vector(dir, speed);
	check = add_vector(obj->pos, multiply_vector(check, speed + 0.3));
	if ((int)check.x != (int)player->pos.x
		|| (int)check.y != (int)player->pos.y)
	{
		update_sprite_anim(obj, 1);
		obj->pos = add_vector(obj->pos, dist);
	}
	else
	{
		update_sprite_anim(obj, 0);
		if (obj->spr_index == ENEMY3 && obj->elapsed_time >= 0.15)
		{
			player->damaged = true;
			player->hp -= 2;
		}
	}
}

void	update_sprites(t_mlx *mlx, t_player *player, t_list *objs_lst)
{
	t_objs	*obj;
	double	speed;

	obj = NULL;
	speed = (PL_SPEED) * mlx->delta;
	while (objs_lst != NULL)
	{
		obj = (t_objs *)objs_lst->content;
		if (obj->type == ENEMY)
		{
			if (obj->state == 1)
				sprite_move(player, obj, speed);
			else
				obj->spr_index = ENEMY1;
		}
		objs_lst = objs_lst->next;
	}
}
