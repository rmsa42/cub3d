/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:37:58 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/10 16:53:17 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_sprite	xpm_to_image(t_mlx *mlx, char *texture)
{
	t_sprite	sprite;

	sprite.img.img_ptr = mlx_xpm_file_to_image(mlx->lib, texture,
			&sprite.width, &sprite.height);
	assert(sprite.img.img_ptr != NULL);
	return (sprite);
}
