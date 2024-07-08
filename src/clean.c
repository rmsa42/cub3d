/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 10:08:11 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_destructor(t_sprite *sprite, void *lib)
{
	int	i;

	i = 0;
	while (i < SPRITE_NBR)
	{
		if (sprite[i].img.img_ptr)
			mlx_destroy_image(lib, sprite[i++].img.img_ptr);
		else
			i++;
	}
}

void	mlx_destructor(void *lib, void *window)
{
	if (window != NULL)
	{
		mlx_clear_window(lib, window);
		mlx_destroy_window(lib, window);
	}
	if (lib != NULL)
	{
		mlx_destroy_display(lib);
		free(lib);
	}
}

void	map_destructor(t_map *map)
{
	int	i;

	i = 0;
	while (map->config_map[i])
	{
		if (map->config_map[i])
			free(map->config_map[i]);
		i++;
	}
	if (map->game_map != NULL)
		ft_free_dp((void **)map->game_map);
}

int	close_game(t_mlx *mlx, int status)
{
	sprite_destructor(mlx->sprite, mlx->lib);
	map_destructor(&mlx->map);
	mlx_destructor(mlx->lib, mlx->window);
	exit(status);
}

void	print_error(char *str, int status, t_mlx *mlx)
{
	ft_fprintf(STDERR_FILENO, "Error\n");
	ft_fprintf(STDERR_FILENO, "%s", str);
	close_game(mlx, status);
}
