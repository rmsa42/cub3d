/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/23 13:37:16 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	update(t_mlx *mlx)
{
	t_player	*player;
	t_v2D		*movement;
	t_v2D		velocity;
	
	player = &mlx->player;
	movement = &mlx->player.movement;

	/* printf("movement Pos: %f, %f\n", movement->x, movement->y); */
	velocity = multiply_vector(normalize_vector(*movement), create_vector(DELTA, DELTA));
	player->pos = add_vector(player->pos, velocity);
	
	return (0);
}

int	handle_keyPress(int keycode, t_mlx *mlx)
{
	t_v2D		*movement;
	
	/* printf("%d\n", keycode); */
	movement = &mlx->player.movement;
	if (keycode == ESC)
		close_game(mlx);
	else if (keycode == W)
		movement->y = -1;
	else if (keycode == S)
		movement->y = 1;
	else if (keycode == A)
		movement->x = -1;
	else if (keycode == D)
		movement->x = 1;
	else if (keycode == LARROW)
		mlx->player.angle -= 0.1;
	else if (keycode == RARROW)
		mlx->player.angle += 0.1;
	return (0);
}

int	handle_keyRelease(int keycode, t_mlx *mlx)
{
	t_v2D		*movement;
	
	movement = &mlx->player.movement;
	if (keycode == W)
		movement->y = 0;
	else if (keycode == S)
		movement->y = 0;
	else if (keycode == A)
		movement->x = 0;
	else if (keycode == D)
		movement->x = 0;
	return(0);
}
