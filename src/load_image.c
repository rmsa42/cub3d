/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:31:14 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/18 14:50:47 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*xpm_to_image(t_mlx *mlx)
{
	int h = 0;
	int w = 0;
	void	*img = NULL;

	img = mlx_xpm_file_to_image(mlx->lib, "wall.xpm", &w, &h);
	assert(img != NULL);
	printf("H: %d\n", h);
	printf("W: %d\n", w);
	
	return (img);
	/* mlx_xpm_file_to_image(mlx->lib, "floor.xpm", SIZE, SIZE); */
}
