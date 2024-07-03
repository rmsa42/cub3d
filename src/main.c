/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:01:42 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/03 14:03:08 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	mlx->f_color = 0;
	mlx->c_color = 0;
	ft_memset(&mlx->buffer, 0, sizeof(t_image));
	ft_memset(mlx->sprite, 0, sizeof(t_sprite) * SPRITE_NBR);
	ft_memset(&mlx->map, 0, sizeof(t_map));
	ft_memset(&mlx->player, 0, sizeof(t_player));
	ft_memset(&mlx->ray, 0, sizeof(t_ray));
}

void	init_map(char **argv, t_mlx *mlx)
{
	t_map	*map;

	map = &mlx->map;
	if (map_parser(argv[1], map))
		print_error("Invalid Map\n", EXIT_FAILURE, mlx);
	if (map->height > HEIGHT || map->width > WIDTH)
		print_error("Invalid Map Size\n", EXIT_FAILURE, mlx);
	if (call_flood_fill(mlx, &mlx->map))
		print_error("", 1, mlx);
	if (check_conf(mlx, mlx->map.config_map, mlx->sprite))
		print_error("Invalid Map Configuration\n", EXIT_FAILURE, mlx);
}

void	start_game(t_mlx *mlx)
{
	mlx_hook(mlx->window, DestroyNotify, ButtonPressMask, close_game, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, handle_key_press, mlx);
	mlx_hook(mlx->window, KeyRelease, KeyReleaseMask,
		handle_key_release, &mlx->player);
	mlx_loop_hook(mlx->lib, game_loop, mlx);
	mlx_loop(mlx->lib);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc > 2 || argc < 2)
		return (ft_fprintf(STDERR_FILENO, "Invalid Args\n"), 1);
	mlx.lib = mlx_init();
	if (mlx.lib == NULL)
		return (ft_fprintf(STDERR_FILENO, "MLX Failure\n"), 1);
	init_mlx_struct(&mlx);
	init_map(argv, &mlx);
	if (set_map(&mlx.map, &mlx.player))
		print_error("Invalid Map(Too many players)\n", EXIT_FAILURE, &mlx);
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	if (mlx.window == NULL)
		print_error("Mlx Window Fail\n", EXIT_FAILURE, &mlx);
	start_game(&mlx);
	return (0);
}
