/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:33:29 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/19 17:35:20 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "vector2D.h"

int main(int argc, char *argv[])
{
	// game loop
	
	// Handle Event
	// Update
	// Render
	
	t_mlx	mlx;
	
	mlx.map = init_map(argv[1]);
	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	
	mlx.sprite[0] = xpm_to_image(&mlx, "wall.xpm");
	mlx.sprite[1] = xpm_to_image(&mlx, "enemy.xpm");
	assert(mlx.sprite[0].img_ptr != NULL);
	assert(mlx.sprite[1].img_ptr != NULL);
	
	mlx.window = mlx_new_window(mlx.lib, 800, 600, "cub3d");
	assert(mlx.window != NULL);
	
	
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_event, &mlx);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
