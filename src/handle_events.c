/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/29 15:12:52 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	t_v2D		norm;
	
	player = &mlx->player;
	norm = normalize_vector(mlx->player.direction);
	if (keycode == ESC)
		close_game(mlx);
	else if (keycode == W)
		player->pos = add_vector(player->pos, multiply_vector(norm, SPEED));
	else if (keycode == S)
		player->pos = minus_vector(player->pos, multiply_vector(norm, SPEED));
	else if (keycode == A)
		player->pos = minus_vector(player->pos, multiply_vector(perp_vector(norm), SPEED));
	else if (keycode == D)
		player->pos = add_vector(player->pos, multiply_vector(perp_vector(norm), SPEED));
	else if (keycode == LARROW)
	{
		player->direction = rotate(player->direction, -2);
		player->plane = rotate(player->plane, -2);
	}
	else if (keycode == RARROW)
	{
		// Se FOV != 90, o plane precisa de ser multiplicado pelo length do vetor plane
		player->direction = rotate(player->direction, 2);
		player->plane = rotate(player->plane, 2);
	}
	return (0);
}

