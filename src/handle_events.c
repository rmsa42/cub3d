/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:56:49 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/03 14:01:16 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_v2D	rotate(t_v2D vector, int degree)
{
	t_v2D	new_vector;
	double	angle;

	angle = degree * ((double)PI / 180);
	new_vector.x = (vector.x * cos(angle) - vector.y * sin(angle));
	new_vector.y = (vector.x * sin(angle) + vector.y * cos(angle));
	return (new_vector);
}

void	player_move(t_player *player, char **game_map, t_v2D x, t_v2D y)
{
	t_v2D	dist;
	t_v2D	new_pos;
	t_v2D	check;
	t_v2D	offset;

	new_pos = add_vector(x, y);
	new_pos = normalize_vector(new_pos);
	dist = multiply_vector(new_pos, (double)SPEED);
	offset = multiply_vector(new_pos, (double)SPEED + 0.1);
	check = add_vector(player->pos, offset);
	new_pos = add_vector(player->pos, dist);
	if (game_map[(int)check.y][(int)check.x] != '1')
		player->pos = new_pos;
}

void	update(t_player *player, t_map *map)
{
	t_v2D	y_axis;
	t_v2D	x_axis;
	double	dist;

	y_axis = multiply_vector(player->direction, player->movement.y);
	x_axis = multiply_vector(player->plane, player->movement.x);
	player_move(player, map->game_map, x_axis, y_axis);
	dist = player->angle * (double)ROTATION_SPEED;
	player->direction = rotate(player->direction, dist);
	player->plane = rotate(player->plane, dist);
}

int	handle_key_press(int keycode, t_mlx *mlx)
{
	t_player	*player;

	player = &mlx->player;
	if (keycode == ESC || keycode < 0)
		close_game(mlx, 0);
	else if (keycode == W)
		player->movement.y = 1;
	else if (keycode == S)
		player->movement.y = -1;
	else if (keycode == A)
		player->movement.x = -1;
	else if (keycode == D)
		player->movement.x = 1;
	else if (keycode == LARROW)
		player->angle = -1;
	else if (keycode == RARROW)
		player->angle = 1;
	return (0);
}

int	handle_key_release(int keycode, t_player *player)
{
	if (keycode == W || keycode == S)
		player->movement.y = 0;
	else if (keycode == A || keycode == D)
		player->movement.x = 0;
	else if (keycode == LARROW || keycode == RARROW)
		player->angle = 0;
	return (0);
}
