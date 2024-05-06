/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/06 17:42:53 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_image	new_image(t_mlx *mlx)
{
	t_image	img;

	img.img_ptr = mlx_new_image(mlx->lib, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

int	render(t_mlx *mlx)
{
	mlx->img = new_image(mlx);
	mlx->sprite[0].img.addr = mlx_get_data_addr(mlx->sprite[0].img.img_ptr,
		&mlx->sprite[0].img.bits_per_pixel, &mlx->sprite[0].img.line_length, &mlx->sprite[0].img.endian);
	assert(mlx->sprite[0].img.addr != NULL);
	ft_grua(mlx);
	mlx_destroy_image(mlx->lib, mlx->img.img_ptr);
	return (0);
}
