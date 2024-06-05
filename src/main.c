/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:39:03 by jmarinho          #+#    #+#             */
/*   Updated: 2024/06/05 17:07:35 by jmarinho         ###   ########.fr       */
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
	player.plane = create_vector((double)FOV / 90, 0);
	player.movement = create_vector(0, 0);
	player.angle = 0.1;
	return (player);
}

int	shift_color(int *rgb)
{
	int	color;

	color = (rgb[0] << 16 | rgb[1] << 8
			| rgb[2]);
	return (color);
}

int	*ft_conv_str_to_int(char *str)
{
	char	**split;
	int		*int_rgb;
	int		i;

	i = -1;
	split = ft_split(str, ',');
	int_rgb = ft_calloc(3, sizeof(int));
	while (++i < 3)
		int_rgb[i] = ft_atoi(split[i]);
	return (int_rgb);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	ft_check_b4_init(argc, argv, &mlx);
	mlx.sprite[0] = xpm_to_image(&mlx, "./sprites/north_wall.xpm");
	mlx.sprite[1] = xpm_to_image(&mlx, mlx.map.config_map[SO]);
	mlx.sprite[2] = xpm_to_image(&mlx, mlx.map.config_map[EA]);
	mlx.sprite[3] = xpm_to_image(&mlx, mlx.map.config_map[WE]);
	mlx.c_color = shift_color(ft_conv_str_to_int(mlx.map.config_map[C]));
	mlx.f_color = shift_color(ft_conv_str_to_int(mlx.map.config_map[F]));
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	assert(mlx.window != NULL);
	map_draw(&mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease,
		&mlx.player);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	return (0);
}
