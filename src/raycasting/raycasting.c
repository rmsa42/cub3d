/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/22 17:42:30 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_grua(t_mlx *mlx)
{
	t_v2D		camera;
	t_player	*player;
	t_map		*map;

	player = &mlx->player;
	map = &mlx->map;
	printf("Player Pos: %f, %f\n", player->direction.x, player->direction.y);
	camera = perp_vector(player->direction);
	printf("Camera Pos: %f, %f\n", camera.x, camera.y);
}
