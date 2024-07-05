/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:41:47 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/04 11:49:43 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	put_tiles(t_mlx *mlx, int x, int y, int tile_size)
{
	int	i;
	int	j;
	int	color;
	int	tile_x;
	int	tile_y;

	color = get_color(x, y, mlx->map);
	tile_x = x * tile_size;
	tile_y = y * tile_size;
	i = -1;
	while (++i < tile_size)
	{
		j = -1;
		while (++j < tile_size)
			pixel_put(&mlx->img, tile_x + i, tile_y + j, color);
	}
}
