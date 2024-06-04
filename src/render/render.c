/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/06/04 17:04:13 by jmarinho         ###   ########.fr       */
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
	int	i;

	i = -1;
	update(mlx);
	mlx->img = new_image(mlx);
	while (++i < 5)
	{
		mlx->sprite[i].img.addr = mlx_get_data_addr(mlx->sprite[i].img.img_ptr,
				&mlx->sprite[i].img.bits_per_pixel,
				&mlx->sprite[i].img.line_length, &mlx->sprite[i].img.endian);
	}
	ft_grua(mlx);
	mlx_destroy_image(mlx->lib, mlx->img.img_ptr);
	return (0);
}
