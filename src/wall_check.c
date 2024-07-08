/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:19:39 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/05 15:39:08 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_wall_collision(t_map *map, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map->game_map[map_y][map_x] == '1')
		return (true);
	return (false);
}

bool	move_check(t_mlx *mlx, t_v2D check)
{
	bool	collision;

	collision = false;
	if (is_wall_collision(&mlx->map, check.x - 0.1, check.y - 0.1)
		|| is_wall_collision(&mlx->map, check.x + 0.1, check.y - 0.1)
		|| is_wall_collision(&mlx->map, check.x - 0.1, check.y + 0.1)
		|| is_wall_collision(&mlx->map, check.x + 0.1, check.y + 0.1))
		collision = true;
	return (collision);
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
