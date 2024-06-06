/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/06/06 11:48:24 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Update Function: Fazer melhor a rotaçao do jogador

t_v2D	rotate(t_v2D vector, int degree)
{
	t_v2D	newV;
	double	angle;
	
	angle = degree * ((double)PI / 180);
	newV.x = (vector.x * cos(angle) - vector.y * sin(angle)) * ROTATION_SPEED;
	newV.y = (vector.x * sin(angle) + vector.y * cos(angle)) * ROTATION_SPEED;
	return (newV);
}

void	player_move(t_player *player, char **game_map, t_v2D x, t_v2D y)
{
	t_v2D	velocity;
	t_v2D	new_pos;
	t_v2D	check;
	t_v2D	offset;

	new_pos = add_vector(x, y);
	new_pos = normalize_vector(new_pos);
	velocity = multiply_vector(new_pos, SPEED);
	offset = multiply_vector(new_pos, SPEED + 0.1);
	check = add_vector(player->pos, offset);
	new_pos = add_vector(player->pos, velocity);
	if (game_map[(int)check.y][(int)check.x] != '1')
		player->pos = new_pos;
}

void	update(t_player *player, t_map *map)
{
	t_v2D	y_axis;
	t_v2D	x_axis;
	
	y_axis = multiply_vector(player->direction, player->movement.y);
	x_axis = multiply_vector(player->plane, player->movement.x);
	player_move(player, map->game_map, x_axis, y_axis);
	
	player->direction = add_vector(player->direction, rotate(player->direction, player->angle));
	player->direction = normalize_vector(player->direction);
	player->plane = add_vector(player->plane, perp_vector(player->direction));
	player->plane = normalize_vector(player->plane);
	player->plane = multiply_vector(player->plane, player->fov);
}

int	handle_keyPress(int keycode, t_mlx *mlx)
{
	t_player	*player;

	player = &mlx->player;
	if (keycode == ESC)
		close_game(mlx);
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

int	handle_keyRelease(int keycode, t_player *player)
{
	if (keycode == W || keycode == S)
		player->movement.y = 0;
	else if (keycode == A || keycode == D)
		player->movement.x = 0;
	else if (keycode == LARROW || keycode == RARROW)
		player->angle = 0;
	return (0);
}
