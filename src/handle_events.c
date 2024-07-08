/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:56:49 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/05 15:38:13 by rumachad         ###   ########.fr       */
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

void	update(t_mlx *mlx, t_player *player)
{
	t_v2D		new_pos;
	t_v2D		check;
	double		dist;

	new_pos = get_position(player, (double)SPEED);
	check = get_position(player, (double)SPEED + 0.1);
	if (!move_check(mlx, check))
		player->pos = new_pos;
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
