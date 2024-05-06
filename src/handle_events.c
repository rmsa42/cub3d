/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/06 17:47:59 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Update Function: Calculo para as novas coordenadas do jogador

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
	if (keycode == W)
		player->pos = add_vector(player->pos, multiply_vector(norm, SPEED));
	if (keycode == S)
		player->pos = minus_vector(player->pos, multiply_vector(norm, SPEED));
	if (keycode == A)
		player->pos = minus_vector(player->pos, multiply_vector(perp_vector(norm), SPEED));
	if (keycode == D)
		player->pos = add_vector(player->pos, multiply_vector(perp_vector(norm), SPEED));
	if (keycode == LARROW)
	{
		player->direction = rotate(player->direction, -3);
		player->plane = rotate(player->plane, -3);
	}
	if (keycode == RARROW)
	{
		player->direction = rotate(player->direction, 3);
		player->plane = rotate(player->plane, 3);
	}
	return (0);
}
