/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:31:14 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/10 16:39:05 by rumachad         ###   ########.fr       */
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

void	start_image_sprite(t_sprite *sprite)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		sprite[i].img.addr = mlx_get_data_addr(sprite[i].img.img_ptr,
				&sprite[i].img.bits_per_pixel,
				&sprite[i].img.line_length, &sprite[i].img.endian);
	}
}

t_image	start_image_buffer(void *lib)
{
	t_image	img;

	img.img_ptr = mlx_new_image(lib, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}