/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/06/06 12:04:26 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "vector2D.h"

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

int	render(t_mlx *mlx)
{
	update(&mlx->player, &mlx->map);
	mlx->buffer = start_image_buffer(mlx->lib);
	ft_grua(mlx);
	mlx_destroy_image(mlx->lib, mlx->buffer.img_ptr);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	mlx.lib = mlx_init();
	if (mlx.lib == NULL)
		return (perror("MLX Failure\n"), -1);
	ft_check_b4_init(argc, argv, &mlx);
	mlx.sprite[0] = xpm_to_image(&mlx, "./sprites/north_wall.xpm");
	mlx.sprite[1] = xpm_to_image(&mlx, mlx.map.config_map[SO]);
	mlx.sprite[2] = xpm_to_image(&mlx, mlx.map.config_map[EA]);
	mlx.sprite[3] = xpm_to_image(&mlx, mlx.map.config_map[WE]);
	mlx.c_color = shift_color(ft_conv_str_to_int(mlx.map.config_map[C]));
	mlx.f_color = shift_color(ft_conv_str_to_int(mlx.map.config_map[F]));
	set_map(&mlx.map, &mlx.player);
	mlx.window = mlx_new_window(mlx.lib, WIDTH, HEIGHT, "cub3D");
	if (mlx.window == NULL)
		return (perror("MLX Window Failure\n"), -1);
	mlx_hook(mlx.window, DestroyNotify, ButtonPressMask, close_game, &mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, handle_keyPress, &mlx);
	mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, handle_keyRelease,
		&mlx.player);
	mlx_loop_hook(mlx.lib, render, &mlx);
	mlx_loop(mlx.lib);
	return (0);
}
