/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/24 12:45:01 by rumachad         ###   ########.fr       */
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
	t_v2D		norm;
	
	/* printf("%d\n", keycode); */
	movement = &mlx->player.movement;
	norm = normalize_vector(mlx->player.direction);
	if (keycode == ESC)
		close_game(mlx);
	else if (keycode == W)
		*movement = add_vector(*movement, create_vector(norm.x, norm.y));
	else if (keycode == S)
		*movement = add_vector(*movement, create_vector(-norm.x, -norm.y));
	else if (keycode == A)
		*movement = add_vector(*movement, perp_vector(create_vector(-norm.x, -norm.y)));
	else if (keycode == D)
		*movement = add_vector(*movement, perp_vector(norm));
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
		*movement = create_vector(0, 0);
	else if (keycode == S)
		*movement = create_vector(0, 0);
	else if (keycode == A)
		*movement = create_vector(0, 0);
	else if (keycode == D)
		*movement = create_vector(0, 0);
	return(0);
}
