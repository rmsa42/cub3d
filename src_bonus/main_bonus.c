/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/09 15:22:31 by rumachad         ###   ########.fr       */
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

int	shift_color(int *rgb)
{
	int	color;
	
	color = (rgb[0] << 16 | rgb[1] << 8
		| rgb[2]);
	return (color);
}

int	check_map(t_mlx *mlx, char **conf_map)
{
	int	i;
	int	k;
	int	*rgb;

	k = 0;
	i = 0;
	rgb = (int *)malloc(sizeof(int) * 3);
	if (rgb == NULL)
		return (0);
	while (conf_map[i])
	{
		k = check_element(conf_map[i]);
		if (k >= 0 && k < 4)
		{
			if (check_path(conf_map[i] + 2))
				return (-1);
			mlx->sprite[k] = xpm_to_image(mlx, conf_map[i] + 3);
		}
		else if (k >= 4)
		{
			if (check_rgb(&rgb, conf_map[i] + 1))
				return (-1);
			mlx->sprite[k].color = shift_color(rgb);
		}
		i++;
	}
	free(rgb);
	return (0);
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
	
	if (check_map(&mlx, mlx.map.config_map))
		return (printf("Check Error\n"), -1);
	
	mlx.sprite[6] = xpm_to_image(&mlx, "./sprites/enemy.xpm");
	assert(mlx.sprite[6].img.img_ptr != NULL);

	// Create Window
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	assert(mlx.window != NULL);
	
	map_draw(&mlx);
	print_vector(mlx.enemy.pos);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease, &mlx.player);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
