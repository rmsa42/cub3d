/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:55:40 by cacarval          #+#    #+#             */
/*   Updated: 2024/05/10 15:00:13 by cacarval         ###   ########.fr       */
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
	player.movement = create_vector(0, 0);
	player.angle = 0.1;
	player.fov = (double)FOV / 90;
	return (player);
}

char	**teste(char **map)
{
	char	**conf_map;
	int		i;

	i = -1;
	conf_map = (char **)malloc(sizeof(char *) * 7);
	while (++i < 6)
		conf_map[i] = map[i];
	conf_map[6] = 0;
	return (conf_map);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	mlx.map = init_map(argv[1]);
	mlx.map.config_map = teste(mlx.map.game_map);
	if (check_config(&mlx, mlx.map.config_map))
		return (printf("Check Error\n"), -1);
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	assert(mlx.window != NULL);
	map_draw(&mlx);
	start_image_sprite(mlx.sprite);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keypress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, \
			handle_keyrelease, &mlx.player);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	(void)argc;
	return (0);
}
