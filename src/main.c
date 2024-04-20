/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:33:29 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/20 01:32:01 by rumachad         ###   ########.fr       */
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
	
	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	
	// Map init / Parser
	mlx.map = init_map(argv[1]);
	mlx.player.direction = create_vector(0, 0);
	
	// Sprite init
	mlx.sprite[0] = xpm_to_image(&mlx, "wall.xpm");
	mlx.sprite[1] = xpm_to_image(&mlx, "enemy.xpm");
	assert(mlx.sprite[0].img_ptr != NULL);
	assert(mlx.sprite[1].img_ptr != NULL);
	
	// Create Window
	mlx.window = mlx_new_window(mlx.lib, 800, 600, "cub3d");
	assert(mlx.window != NULL);
	
	
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease, &mlx);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
