/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/06/28 12:58:02 by rumachad         ###   ########.fr       */
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

int	game_loop(t_mlx *mlx)
{
	update(&mlx->player, &mlx->map);
	mlx->buffer = start_image_buffer(mlx->lib);
	ft_grua(mlx);
	mlx_destroy_image(mlx->lib, mlx->buffer.img_ptr);
	return (0);
}

void	init_mlx_struct(t_mlx *mlx)
{
	mlx->window = NULL;
	mlx->side = 0;
	mlx->sprite_index = 0;
	mlx->tex_x = 0;
	mlx->side = 0;
	mlx->line_height = 0;
	mlx->scale = 0;
	mlx->tex_pos = 0;
	ft_memset(&mlx->buffer, 0, sizeof(t_image));
	ft_memset(mlx->sprite, 0, sizeof(t_sprite) * SPRITE_NBR);
	ft_memset(&mlx->map, 0, sizeof(t_map));
	ft_memset(&mlx->player, 0, sizeof(t_player));
	ft_memset(&mlx->ray, 0, sizeof(t_ray));
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{	
	t_mlx	mlx;
	
	if (argc > 2)
		return (ft_fprintf(STDERR_FILENO, "Invalid Args\n"), 1);
	mlx.lib = mlx_init();
	if (mlx.lib == NULL)
		return (ft_fprintf(STDERR_FILENO, "MLX Failure\n"), 1);
	init_mlx_struct(&mlx);
	if (map_parser(argv[1], &mlx.map))
		print_error("Invalid Map\n", EXIT_FAILURE, &mlx);
	if (call_flood_fill(&mlx, &mlx.map))
		print_error("", 1, &mlx);
	if (check_config(&mlx, mlx.map.config_map))
		print_error("Invalid Map Configuration\n", EXIT_FAILURE, &mlx);
	if (set_map(&mlx.map, &mlx.player))
		print_error("Invalid Map(Too many players)\n", EXIT_FAILURE, &mlx);
	
	// Create Window
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	if (mlx.window == NULL)
		print_error("Mlx Window Fail\n", EXIT_FAILURE, &mlx);
	
	// Game Loop
	mlx_hook(mlx.window, DestroyNotify, ButtonPressMask, close_game, &mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease, &mlx.player);
	mlx_loop_hook(mlx.lib, game_loop, &mlx);
	mlx_loop(mlx.lib);
	return (0);	
}
