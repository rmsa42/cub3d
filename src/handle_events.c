/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/20 01:31:50 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	update(t_mlx *mlx)
{
	t_player	*player;
	t_v2D		*direction;
	t_v2D		velocity;
	
	player = &mlx->player;
	direction = &mlx->player.direction;

	/* printf("Direction Pos: %f, %f\n", direction->x, direction->y); */
	velocity = multiply_vector(normalize_vector(*direction), create_vector(DELTA, DELTA));
	player->pos = add_vector(player->pos, velocity);
	/* printf("Player Pos: %f, %f\n", player->pos.x, player->pos.y); */
	
	return (0);
}

int	handle_keyPress(int keycode, t_mlx *mlx)
{
	t_v2D		*direction;
	
	/* printf("%d\n", keycode); */
	direction = &mlx->player.direction;
	if (keycode == ESC)
		close_game(mlx);
	else if (keycode == W)
		direction->y = -1;
	else if (keycode == S)
		direction->y = 1;
	else if (keycode == A)
		direction->x = -1;
	else if (keycode == D)
		direction->x = 1;
	return (0);
}

int	handle_keyRelease(int keycode, t_mlx *mlx)
{
	t_v2D		*direction;
	
	direction = &mlx->player.direction;
	if (keycode == W)
		direction->y = 0;
	else if (keycode == S)
		direction->y = 0;
	else if (keycode == A)
		direction->x = 0;
	else if (keycode == D)
		direction->x = 0;
	return(0);
}
