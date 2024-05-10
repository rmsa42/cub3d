/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/10 19:03:40 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	clear_sprites(t_sprite *sprite, void *lib)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (sprite[i].img.img_ptr)
			mlx_destroy_image(lib, sprite[i++].img.img_ptr);
		else
			i++;
	}
}

int	close_game(t_mlx *mlx)
{
	clear_sprites(mlx->sprite, mlx->lib);
	if (mlx->lib && mlx->window)
	{
		mlx_clear_window(mlx->lib, mlx->window);
		mlx_destroy_window(mlx->lib, mlx->window);
	}
	if (mlx->map.config_map)
		free(mlx->map.config_map);
	if (mlx->map.game_map)
		ft_free_dp((void **)mlx->map.game_map);
	if (mlx->lib)
	{
		mlx_destroy_display(mlx->lib);
		free(mlx->lib);
	}
	exit(0);
	return (0);
}
