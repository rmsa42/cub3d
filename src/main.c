/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/09 10:42:28 by rumachad         ###   ########.fr       */
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
	player.movement = create_vector(0,0);
	player.angle = 0.1;
	return (player);
}

int	shift_color(t_sprite sprite)
{
	int	color;
	
	color = (sprite.rgb[0] << 16 | sprite.rgb[1] << 8
		| sprite.rgb[2]);
	return (color);
}

int	check_map(t_mlx *mlx, char **conf_map)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (conf_map[i])
	{
		k = check_element(conf_map[i]);
		if (k >= 0 && k < 4)
		{
			if (check_path(conf_map[k] + 2))
				return (-1);
			mlx->sprite[k] = xpm_to_image(mlx, conf_map[k] + 2);
		}
		else if (k >= 4)
		{
			if (check_rgb(&mlx->sprite[k], conf_map[k] + 2))
				return (-1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{	
	t_mlx	mlx;
	
	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	
	mlx = ft_check_b4_init(argc, argv, &mlx);
	
	/* print_map(mlx.map.config_map); */
	// Map init / Parser / Sprite Init
	if (check_map(&mlx, mlx.map.config_map))
		return (printf("Check Error\n"), -1);
	/* mlx.sprite[0] = xpm_to_image(&mlx, "sprites/wall1.xpm");
	mlx.sprite[1] = xpm_to_image(&mlx, "sprites/wall2.xpm");
	mlx.sprite[2] = xpm_to_image(&mlx, "sprites/wall3.xpm");
	mlx.sprite[3] = xpm_to_image(&mlx, "sprites/wall5.xpm");
	mlx.sprite[4] = xpm_to_image(&mlx, "sprites/sky.xpm"); */

	mlx.c_color = shift_color(mlx.sprite[4]);
	mlx.f_color = shift_color(mlx.sprite[5]);
	
	// Create Window
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	assert(mlx.window != NULL);
	
	map_draw(&mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease, &mlx.player);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
