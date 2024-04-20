/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/20 00:50:15 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_grua(t_player *player)
{
	t_v2D	camera;

	printf("Player Pos: %f, %f\n", player->pos.x, player->pos.y);
	camera = perp_vector(player->pos);
	printf("Camera Pos: %f, %f\n", camera.x, camera.y);
}
