/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/19 17:36:01 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render(t_mlx *mlx)
{
	mlx_clear_window(mlx->lib, mlx->window);
	map_draw(mlx);
	image_to_window(mlx, mlx->sprite[1], mlx->player.pos.x, mlx->player.pos.y);
	ft_grua(&mlx->player);
	
	return (0);
}
