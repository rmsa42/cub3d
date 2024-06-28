/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:31:14 by rumachad          #+#    #+#             */
/*   Updated: 2024/06/28 16:06:43 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pixel_get(t_image *img, int pixel_x, int pixel_y)
{
	int	color;

	color = *(unsigned int *)(img->addr + (pixel_y * img->line_length
				+ pixel_x * (img->bits_per_pixel / 8)));
	return (color);
}

void	pixel_put(t_image *img, int pixelX, int pixelY, int color)
{
	char	*dst;

	dst = img->addr + (pixelY * img->line_length
			+ pixelX * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_image	start_image_buffer(void *lib)
{
	t_image	img;

	img.img_ptr = mlx_new_image(lib, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

t_sprite	xpm_to_image(t_mlx *mlx, char *texture)
{
	t_sprite	sprite;
	t_image		img;

	img.img_ptr = mlx_xpm_file_to_image(mlx->lib, texture,
			&sprite.width, &sprite.height);
	if (img.img_ptr == NULL)
		print_error("Invalid Sprite\n", EXIT_FAILURE, mlx);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
				&img.line_length, &img.endian);
	if (img.addr == NULL)
		print_error("Invalid Sprite Address\n", EXIT_FAILURE, mlx);
	sprite.img = img;
	return (sprite);
}
