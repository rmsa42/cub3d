/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/10 12:23:04 by rumachad         ###   ########.fr       */
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
	print_vector(newV);
	return (newV);
}

void	update(t_mlx *mlx)
{
	t_player *player;
	t_v2D	velocity;
	t_v2D	y_axis;
	t_v2D	x_axis;
	t_v2D	new_pos;
	
	player = &mlx->player;
	y_axis = multiply_vector(player->direction, player->movement.y);
	x_axis = multiply_vector(player->plane, player->movement.x);
	new_pos = add_vector(y_axis, x_axis);
	new_pos = normalize_vector(new_pos);
	velocity = multiply_vector(new_pos, SPEED);
	player->pos = add_vector(player->pos, velocity);
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
