/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/10 19:06:47 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "vector2D.h"

/* void	*my_malloc(size_t size)
{
	(void)size;
	return (NULL);
} */

char **teste(char **map)
{
	char	**conf_map;

	conf_map = (char **)malloc(sizeof(char *) * 7);
	if (conf_map == NULL)
		return (NULL);
	for (int i = 0; i < 6; i++)
	{
		conf_map[i] = map[i];
	}
	conf_map[6] = 0;
	return (conf_map);
}

int	render(t_mlx *mlx)
{
	update(mlx);
	mlx->buffer = start_image_buffer(mlx->lib);
	ft_grua(mlx);
	mlx_destroy_image(mlx->lib, mlx->buffer.img_ptr);
	return (0);
}

int main(int argc, char *argv[])
{	
	t_mlx	mlx;
	
	ft_memset((void *)&mlx, 0, sizeof(t_mlx));
	mlx.lib = mlx_init();
	if (mlx.lib == NULL)
		return (perror("MLX Failure\n"), -1);
	
	/* mlx = ft_check_b4_init(argc, argv, &mlx); */
	
	// Map init / Parser / Sprite Init
	mlx.map = init_map(argv[1]);
	mlx.map.config_map = teste(mlx.map.game_map);
	
	if (check_config(&mlx, mlx.map.config_map))
	{
		close_game(&mlx);
		return (printf("Check Error\n"), -1);
	}

	// Set Map and Sprites
	set_map(&mlx.map, &mlx.player);
	start_image_sprite(mlx.sprite);
	
	// Create Window
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	if (mlx.window == NULL)
		return (perror("MLX Window Failure\n"), -1);
	
	// Game Loop
	mlx_hook(mlx.window, DestroyNotify, ButtonPressMask, close_game, &mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease, &mlx.player);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	
	(void)argc;
	return (0);	
}
