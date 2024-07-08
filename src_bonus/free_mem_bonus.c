/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:54:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 14:20:44 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	free_config(void *lib, t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (sprite[i].img.img_ptr != NULL)
		{
			mlx_destroy_image(lib, sprite[i].img.img_ptr);
			sprite[i].img.img_ptr = NULL;
		}
		i++;
	}
}

void	free_obj_lst(t_list *objs)
{
	t_list	*tmp;

	tmp = NULL;
	while (objs)
	{
		tmp = objs;
		objs = objs->next;
		obj_destructor(tmp);
	}
}

void	free_sprites(void *lib, t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < SPRITE_NBR)
	{
		sprite_destructor(lib, &sprite[i]);
		i++;
	}
}

void	free_map(int nbr_maps, t_map *map)
{
	int	i;

	i = 0;
	while (i < nbr_maps)
	{
		map_destructor(&map[i]);
		i++;
	}
	free(map);
}
