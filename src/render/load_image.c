/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:31:14 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/19 17:35:40 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_sprite	xpm_to_image(t_mlx *mlx, char *texture)
{
	t_sprite	sprite;

	sprite.img_ptr = mlx_xpm_file_to_image(mlx->lib, texture,
						&sprite.width, &sprite.height);
	
	return (sprite);
}

void	image_to_window(t_mlx *mlx, t_sprite sprite, double x, double y)
{
	mlx_put_image_to_window(mlx->lib, mlx->window, sprite.img_ptr,
		x * sprite.width, y * sprite.height);
	/* printf("Sprite Load\n"); */
}
