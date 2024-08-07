/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 14:26:22 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	print_error(char *str, int status, t_mlx *mlx)
{
	ft_fprintf(STDERR_FILENO, "Error\n");
	ft_fprintf(STDERR_FILENO, "%s", str);
	close_game(mlx, status);
}

int	close_game(t_mlx *mlx, int status)
{
	free_sprites(mlx->lib, mlx->sprite);
	free_map(mlx->nbr_maps, mlx->head_map);
	if (mlx->marked_cells != NULL)
		free(mlx->marked_cells);
	free_obj_lst(mlx->objs_lst);
	mlx_destructor(mlx->lib, mlx->window);
	exit(status);
}
