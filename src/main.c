/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:33:29 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/18 15:04:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "vector2D.h"

int main()
{
	// game loop
	
	// Handle Event
	// Update
	// Render

	t_mlx	mlx;
	
	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	
	void	*img = xpm_to_image(&mlx);
	
	mlx.window = mlx_new_window(mlx.lib, 800, 600, "cub3d");
	assert(mlx.window != NULL);
	
	mlx_put_image_to_window(mlx.lib, mlx.window, img, 8 * /*  */, 8 * /*  */);
	
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_event, &mlx);
	mlx_loop(mlx.lib);

/* 	t_v2D v1;
	t_v2D v2;

	v1.x = 20;
	v1.y = 3;
	
	v2.x = 10;
	v2.y = 10;
	
	t_v2D v3 = minus_vector(v1, v2);

	print_vector(v3); */
	return (0);	
}