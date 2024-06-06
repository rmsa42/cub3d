/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:37:58 by rumachad          #+#    #+#             */
/*   Updated: 2024/06/04 17:12:53 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_img_addr(t_image *img)
{
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
				&img->line_length, &img->endian);
}

t_sprite	xpm_to_image(t_mlx *mlx, char *texture)
{
	t_sprite	sprite;

	sprite.img.img_ptr = mlx_xpm_file_to_image(mlx->lib, texture,
			&sprite.width, &sprite.height);
	assert(sprite.img.img_ptr != NULL);
	get_img_addr(&sprite.img);
	assert(sprite.img.addr != NULL);
	return (sprite);
}
