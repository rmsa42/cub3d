/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:43:21 by jmarinho          #+#    #+#             */
/*   Updated: 2024/06/04 16:44:52 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Update Function: Fazer melhor a rotaçao do jogador

void	update(t_mlx *mlx)
{
	t_player	*player;
	t_v2D		velocity;
	t_v2D		y_axis;
	t_v2D		x_axis;
	t_v2D		new_pos;
	t_v2D		check;

	player = &mlx->player;
	y_axis = multiply_vector(player->direction, player->movement.y);
	x_axis = multiply_vector(player->plane, player->movement.x);
	new_pos = add_vector(y_axis, x_axis);
	new_pos = normalize_vector(new_pos);
	velocity = multiply_vector(new_pos, SPEED);
	check = add_vector(player->pos, velocity);
	if (mlx->map.game_map[(int)player->pos.y][(int)player->pos.x] != '1')
		player->pos = check;
}

t_v2D	rotate(t_v2D vector, int degree)
{
	t_v2D	newV;
	double	angle;

	angle = degree * ((double)PI / 180);
	newV.x = vector.x * cos(angle) - vector.y * sin(angle);
	newV.y = vector.x * sin(angle) + vector.y * cos(angle);
	return (newV);
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
	{
		player->direction = rotate(player->direction, -3);
		player->plane = rotate(player->plane, -3);
	}
	else if (keycode == RARROW)
	{
		player->direction = rotate(player->direction, 3);
		player->plane = rotate(player->plane, 3);
	}
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
