/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/23 11:41:54 by jmarinho         ###   ########.fr       */
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

/*void	init_sprites(t_mlx *mlx, char **conf_map)
{
	int		i;
	char	*ele[7];

	i = 0;
	ele[0] = "NO ";
	ele[1] = "SO ";
	ele[2] = "WE ";
	ele[3] = "EA ";
	ele[4] = 0;
	while (conf_map[i])
	{
		if (!ft_strncmp(conf_map[i], ele[i], 2))
			sprite[i] = xpm_to_image();
	}
}*/

int main(int argc, char *argv[])
{	
	t_mlx	mlx;
	
	mlx.lib = mlx_init();
	assert(mlx.lib != NULL);
	mlx = ft_check_b4_init(argc, argv, &mlx);

	#//TODO fazer checkagens ao mapa
	#//TODO fazer checkagens ao xpm. se ponteiro for null retornar erro para nao crashar o programa
	
	exit(0);//delete when no use
	
	// Map init / Parser / Sprite Init
	//inti_sprite(mlx, );
	mlx.sprite[0] = xpm_to_image(&mlx, "sprites/wall1.xpm");
	mlx.sprite[1] = xpm_to_image(&mlx, "sprites/wall2.xpm");
	mlx.sprite[2] = xpm_to_image(&mlx, "sprites/wall3.xpm");
	mlx.sprite[3] = xpm_to_image(&mlx, "sprites/wall5.xpm");
	mlx.sprite[4] = xpm_to_image(&mlx, "sprites/sky.xpm");

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
