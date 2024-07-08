/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:37:02 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 14:26:30 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	init_mlx_structs(t_mlx *mlx)
{
	ft_memset(mlx->sprite, 0, sizeof(t_sprite) * SPRITE_NBR);
	ft_memset(&mlx->ray, 0, sizeof(t_ray));
	ft_memset(&mlx->player, 0, sizeof(t_player));
	ft_memset(&mlx->draw, 0, sizeof(t_draw));
	ft_memset(mlx->dist_buffer, 0, sizeof(double) * WIDTH);
	update_time(&mlx->door_time);
	update_time(&mlx->last_time);
	update_time(&mlx->prev_time);
	update_time(&mlx->current_time);
	mlx->map = ft_calloc(sizeof(t_map), mlx->nbr_maps);
	if (mlx->map == NULL)
		return (1);
	mlx->head_map = mlx->map;
	ft_memset(mlx->map, 0, sizeof(t_map) * mlx->nbr_maps);
	return (0);
}

void	init_mlx_vars(t_mlx *mlx, int ac)
{
	mlx->window = NULL;
	mlx->objs_lst = NULL;
	mlx->marked_cells = NULL;
	mlx->map = NULL;
	mlx->head_map = NULL;
	mlx->num_marked_cells = 0;
	mlx->side = 0;
	mlx->spr_index = 0;
	mlx->spr_hp_index = 0;
	mlx->spr_character_index = 0;
	mlx->spr_coins_index = 0;
	mlx->delta = 0;
	mlx->elapsed_time = 0;
	mlx->elapsed_door = 0;
	mlx->iter_map = 1;
	mlx->nbr_maps = ac - 1;
	mlx->game_state = GAME_STATE;
	mlx->tile_size = 0;
	mlx->f_color = 0;
	mlx->c_color = 0;
}

void	init_map(t_mlx *mlx, int nbr_maps, char **av)
{
	t_map	*map;
	int		i;
	int		k;

	i = 1;
	k = 0;
	map = mlx->map;
	while (i <= nbr_maps)
	{
		if (map_parser(av[i], &map[k]))
			print_error("Invalid Map Config\n", EXIT_FAILURE, mlx);
		if (map[k].height > HEIGHT || map[k].width > WIDTH)
			print_error("Invalid Map Size\n", EXIT_FAILURE, mlx);
		if (call_flood_fill(mlx, &map[k]))
			print_error("Syscall Failure\n", EXIT_FAILURE, mlx);
		i++;
		k++;
	}
	mlx->tile_size = 5.5 *(HEIGHT / 600);
	if (mlx->map->height > 60 || mlx->map->width > 60 || mlx->tile_size < 1)
		mlx->tile_size = 1;
}
