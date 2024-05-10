/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/10 12:31:46 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_image	start_image_buffer(void *lib)
{
	t_image	img;

	img.img_ptr = mlx_new_image(lib, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
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

int	render(t_mlx *mlx)
{
	update(mlx);
	mlx->img = start_image_buffer(mlx->lib);
	ft_grua(mlx);
	mlx_destroy_image(mlx->lib, mlx->img.img_ptr);
	return (0);
}
