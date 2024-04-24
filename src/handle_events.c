/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/24 17:12:17 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_v2D	rotate(t_v2D vector, int degree)
{
	t_v2D	newV;
	double	angle;
	
	angle = (double)FOV / 2 + degree;
	angle = angle * ((double)PI / 180);
	newV.x = vector.x * cos(angle) - vector.y * sin(angle);
	newV.y = vector.x * sin(angle) - vector.y * cos(angle);

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
		player->pos.y += player->direction.y * SPEED;
	else if (keycode == S)
		player->pos.y -= player->direction.y * SPEED;
	else if (keycode == A)
		player->pos.x -= 1 * SPEED;
	else if (keycode == D)
		player->pos.x += 1 * SPEED;
	else if (keycode == LARROW)
	{
		player->direction = rotate(player->direction, 1);
		/* player->plane = rotate(player->plane, 1); */
	}
	return (0);
}

