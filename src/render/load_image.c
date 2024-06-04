/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:31:14 by rumachad          #+#    #+#             */
/*   Updated: 2024/06/04 17:37:02 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pixel_get(t_image *img, int pixel_x, int pixel_y)
{
	int	color;

	color = *(unsigned int *)(img->addr + (pixel_y * img->line_length + pixel_x
				* (img->bits_per_pixel / 8)));
	return (color);
}

void	pixel_put(t_image *img, int pixelX, int pixelY, int color)
{
	char	*dst;

	dst = img->addr + (pixelY * img->line_length + pixelX
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_sprite	xpm_to_image(t_mlx *mlx, char *texture)
{
	t_sprite	sprite;

	sprite.img.img_ptr = mlx_xpm_file_to_image(mlx->lib, texture,
			&sprite.width, &sprite.height);
	if (sprite.img.img_ptr == NULL)
		ft_perror("ERROR\nSome textures are not valid\n", mlx);
	sprite.img.addr = mlx_get_data_addr(sprite.img.img_ptr, &sprite.img.bits_per_pixel,
			&sprite.img.line_length, &sprite.img.endian);
	return (sprite);
}

void	image_to_window(t_mlx *mlx, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(mlx->lib, mlx->window, img_ptr,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}
