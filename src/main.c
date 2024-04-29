/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:33:29 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/29 17:01:39 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "vector2D.h"

t_player	init_player(double x, double y, char tile)
{
	t_player	player;
	int			dir;

	dir = 1;
	player.pos = create_vector(x, y);
	if (tile == 'N')
		player.direction = create_vector(0, -dir);
	else if (tile == 'S')
		player.direction = create_vector(0, dir);
	else if (tile == 'W')
		player.direction = create_vector(-dir, 0);
	else if (tile == 'E')
		player.direction = create_vector(dir, 0);
	player.plane = perp_vector(player.direction);
	return (player);
}

int main(int argc, char *argv[])
{	
	t_mlx	mlx;
	
	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	
	// Map init / Parser / Sprite Init
	mlx.map = init_map(argv[1]);
	mlx.sprite[0] = xpm_to_image(&mlx, "wall.xpm");
	assert(mlx.sprite[0].img_ptr != NULL);
	
	// Create Window
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	assert(mlx.window != NULL);
	
	parser_map(&mlx.map);
	map_draw(&mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
