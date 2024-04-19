/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/19 17:43:50 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	update(t_mlx *mlx, t_v2D direction)
{
	t_player	*player;
	t_v2D		velocity;
	
	player = &mlx->player;
	velocity = multiply_vector(normalize_vector(direction), create_vector(DELTA, DELTA));
	player->pos = add_vector(player->pos, velocity);
	printf("Player Pos: %f, %f\n", player->pos.x, player->pos.y);
}

int	handle_event(int keycode, t_mlx *mlx)
{
	t_v2D		direction;
	
	/* printf("%d\n", keycode); */
	direction = create_vector(0, 0);
	if (keycode == ESC)
		close_game(mlx);
	else if (keycode == W)
		direction = create_vector(0, -1);
	else if (keycode == S)
		direction = create_vector(0, 1);
	else if (keycode == A)
		direction = create_vector(-1, 0);
	else if (keycode == D)
		direction = create_vector(1, 0);
	update(mlx, direction);
	return (0);
}
