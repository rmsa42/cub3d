/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:29:15 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 15:17:34 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	portal_calc(t_player *player, t_v2D old_pos,
		t_v2D check, t_v2D velocity)
{
	if (fabs(velocity.x) > fabs(velocity.y))
	{
		if (fabs(velocity.y) > 0.01)
			player->pos = old_pos;
		else
		{
			if (velocity.x > 0)
				player->pos.x = check.x + 0.5;
			else if (velocity.x < 0)
				player->pos.x = check.x - 0.5;
		}
	}
	else
	{
		if (fabs(velocity.x) > 0.01)
			player->pos = old_pos;
		else
		{
			if (velocity.y > 0)
				player->pos.y = check.y + 0.5;
			else if (velocity.y < 0)
				player->pos.y = check.y - 0.5;
		}
	}
}

t_v2D	get_position(t_player *player, double speed)
{
	t_v2D	dist;
	t_v2D	new_pos;
	t_v2D	y;
	t_v2D	x;

	y = multiply_vector(player->direction, player->movement.y);
	x = multiply_vector(player->plane, player->movement.x);
	new_pos = add_vector(x, y);
	new_pos = normalize_vector(new_pos);
	dist = multiply_vector(new_pos, speed);
	new_pos = add_vector(player->pos, dist);
	return (new_pos);
}

bool	move_check(t_mlx *mlx, t_list *objs_lst, t_v2D check)
{
	bool	collision;

	collision = check_objs_collision(mlx, objs_lst, check);
	if (is_wall_collision(mlx->map, check.x - 0.1, check.y - 0.1)
		|| is_wall_collision(mlx->map, check.x + 0.1, check.y - 0.1)
		|| is_wall_collision(mlx->map, check.x - 0.1, check.y + 0.1)
		|| is_wall_collision(mlx->map, check.x + 0.1, check.y + 0.1))
		collision = true;
	return (collision);
}

void	player_move(t_player *player, char **game_map,
		t_v2D new_pos, t_v2D check)
{
	t_v2D	old_pos;
	t_v2D	dist;

	old_pos = player->pos;
	dist = minus_vector(new_pos, player->pos);
	if (game_map[(int)check.y][(int)check.x] == 'd')
	{
		portal_calc(player, old_pos, check, dist);
		return ;
	}
	player->pos = new_pos;
}

void	update_player(t_mlx *mlx, t_player *player, t_map *map)
{
	t_v2D		new_pos;
	t_v2D		check;
	double		speed;

	if (player->shoot == true)
		update_ball(mlx, player);
	speed = PL_SPEED * mlx->delta;
	new_pos = get_position(player, speed);
	check = get_position(player, speed + 0.1);
	if (!move_check(mlx, mlx->objs_lst, check))
		player_move(player, map->game_map, new_pos, new_pos);
	speed = player->angle * mlx->delta * ROTATION_SPEED;
	player->direction = rotate(player->direction, speed);
	player->plane = rotate(player->plane, speed);
}
