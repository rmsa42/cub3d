/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:33:29 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/24 17:48:32 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "vector2D.h"

t_player	init_player()
{
	t_player	player;

	player.pos = create_vector(0, 0);
	player.direction = create_vector(0, -1);
	player.plane = create_vector(1, 0);
	
	return (player);
}

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
	mlx.player = init_player();
	
	// Sprite init
	mlx.sprite[0] = xpm_to_image(&mlx, "wall.xpm");
	assert(mlx.sprite[0].img_ptr != NULL);
	
	// Create Window
	mlx.window = mlx_new_window(mlx.lib, HEIGHT, WIDTH, "cub3d");
	assert(mlx.window != NULL);
	
	
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
