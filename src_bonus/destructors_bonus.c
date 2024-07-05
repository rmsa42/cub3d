/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:04 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	obj_destructor(t_list *node)
{
	free(node->content);
	free(node);
	node = NULL;
}

void	sprite_destructor(void *lib, t_sprite *sprite)
{
	if (sprite->img.img_ptr != NULL)
		mlx_destroy_image(lib, sprite->img.img_ptr);
	sprite->img.img_ptr = NULL;
}

void	map_destructor(t_map *map)
{
	int	i;

	i = 0;
	while (map->config_map[i])
	{
		if (map->config_map[i])
			free(map->config_map[i]);
		map->config_map[i] = NULL;
		i++;
	}
	if (map->game_map)
		ft_free_dp((void **)map->game_map);
	map->game_map = NULL;
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
