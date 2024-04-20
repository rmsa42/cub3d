/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/20 01:08:54 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render(t_mlx *mlx)
{
	update(mlx);
	mlx_clear_window(mlx->lib, mlx->window);
	map_draw(mlx);
	image_to_window(mlx, mlx->sprite[1], mlx->player.pos.x, mlx->player.pos.y);
	/* ft_grua(&mlx->player); */
	
	return (0);
}
