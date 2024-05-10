/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/10 12:28:58 by rumachad         ###   ########.fr       */
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
	player.movement = create_vector(0, 0);
	player.plane = perp_vector(player.direction);
	player.movement = create_vector(0,0);
	player.angle = 0.1;
	player.fov = (double)FOV / 90;
	return (player);
}

char **teste(char **map)
{
	char	**conf_map;

	conf_map = (char **)malloc(sizeof(char *) * 7);
	for (int i = 0; i < 6; i++)
	{
		conf_map[i] = map[i];
	}
	conf_map[6] = 0;
	return (conf_map);
}

int main(int argc, char *argv[])
{	
	t_mlx	mlx;
	
	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	
	/* mlx = ft_check_b4_init(argc, argv, &mlx); */
	
	// Map init / Parser / Sprite Init
	mlx.map = init_map(argv[1]);
	mlx.map.config_map = teste(mlx.map.game_map);
	
	if (check_config(&mlx, mlx.map.config_map))
		return (printf("Check Error\n"), -1);

	// Create Window
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	assert(mlx.window != NULL);
	
	map_draw(&mlx);
	start_image_sprite(mlx.sprite);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease, &mlx.player);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
