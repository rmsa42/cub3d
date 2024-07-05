/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball_hits_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:27:08 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

bool	ball_hit_wall(t_map *map, t_objs *ball)
{
	if (is_wall_collision(map, ball->pos.x - 0.1, ball->pos.y - 0.1)
		|| is_wall_collision(map, ball->pos.x + 0.1, ball->pos.y + 0.1)
		|| is_wall_collision(map, ball->pos.x + 0.1, ball->pos.y - 0.1)
		|| is_wall_collision(map, ball->pos.x - 0.1, ball->pos.y + 0.1))
		return (true);
	return (false);
}

t_list	*ball_hit_obj(t_list *objs_lst, t_objs *ball)
{
	t_objs	*obj;

	obj = NULL;
	while (objs_lst)
	{
		obj = (t_objs *)objs_lst->content;
		if (obj->type != BALL && (int)ball->pos.x == (int)obj->pos.x
			&& (int)ball->pos.y == (int)obj->pos.y)
		{
			obj->hp--;
			return (objs_lst);
		}
		objs_lst = objs_lst->next;
	}
	return (NULL);
}

void	clean_hit(t_list **objs_list, t_player *player, t_list *hit)
{
	if (hit)
	{
		if (((t_objs *)hit->content)->hp <= 0)
			elim_obj(objs_list, hit);
	}
	elim_obj(objs_list, player->ball_node);
	player->shoot = false;
	player->shoot_anim = false;
}
