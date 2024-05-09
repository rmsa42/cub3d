/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/09 13:56:55 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	// Sprites
	while (i < 4)
		mlx_destroy_image(mlx->lib, mlx->sprite[i++].img.img_ptr);
	// Window
	mlx_clear_window(mlx->lib, mlx->window);
	mlx_destroy_window(mlx->lib, mlx->window);
	mlx_destroy_display(mlx->lib);
	// Map
	free(mlx->map.config_map);
	ft_free_dp((void **)mlx->map.game_map);
	// MLX
	free(mlx->lib);
	exit(0);
}
