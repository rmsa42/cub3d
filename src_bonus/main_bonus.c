/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:26:29 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 16:19:06 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	check_conf(t_mlx *mlx, char **conf_map, t_sprite *sprite)
{
	int	k;

	k = -1;
	while (conf_map[++k] && k < 4)
	{
		if (check_element(mlx, &sprite[k], conf_map[k]))
			print_error("Wrong Textures\n", EXIT_FAILURE, mlx);
	}
	mlx->f_color = check_rgb(conf_map[4] + 1 + advance_space(conf_map[4] + 1));
	mlx->c_color = check_rgb(conf_map[5] + 1 + advance_space(conf_map[5] + 1));
	if (mlx->c_color == -1 || mlx->f_color == -1)
		print_error("Wrong Colors\n", EXIT_FAILURE, mlx);
	return (0);
}

void	start_game(t_mlx *mlx)
{
	mlx_hook(mlx->window, DestroyNotify, ButtonPressMask, close_game, mlx);
	mlx_hook(mlx->window, MotionNotify, PointerMotionMask,
		handle_mouse, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask,
		handle_key_press, mlx);
	mlx_mouse_hook(mlx->window, handle_mouse_press, mlx);
	mlx_hook(mlx->window, KeyRelease, KeyReleaseMask,
		handle_key_release, &mlx->player);
	mlx_mouse_hide(mlx->lib, mlx->window);
	mlx_loop_hook(mlx->lib, game_loop, mlx);
	mlx_loop(mlx->lib);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc < 2)
		return (ft_fprintf(STDERR_FILENO, "Invalid nbr arguments\n"), 1);
	mlx.lib = mlx_init();
	if (mlx.lib == NULL)
		return (ft_fprintf(STDERR_FILENO, "MLX Failure\n"), 1);
	init_mlx_vars(&mlx, argc);
	if (init_mlx_structs(&mlx))
		print_error("Syscall Failure\n", EXIT_FAILURE, &mlx);
	init_map(&mlx, mlx.nbr_maps, argv);
	init_sprite(&mlx, mlx.map->config_map, mlx.sprite);
	set_map(&mlx);
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	if (mlx.window == NULL)
		print_error("Mlx window creation failure\n", EXIT_FAILURE, &mlx);
	start_game(&mlx);
	return (0);
}
