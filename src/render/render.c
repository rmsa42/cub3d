/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/24 16:43:41 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render(t_mlx *mlx)
{
	mlx_clear_window(mlx->lib, mlx->window);
	map_draw(mlx);
	ft_grua(mlx);

	return (0);
}
