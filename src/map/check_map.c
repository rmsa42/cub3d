/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:58:59 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/10 15:13:13 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	shift_color(int *rgb)
{
	int	color;

	color = (rgb[0] << 16 | rgb[1] << 8 | \
			rgb[2]);
	return (color);
}

int	check_tex_rgb(t_mlx *mlx, char *conf_map, int *rgb, int k)
{
	if (k >= 0 && k < 4)
	{
		if (check_path(conf_map + 2))
			return (-1);
		mlx->sprite[k] = xpm_to_image(mlx, conf_map + 3);
	}
	else if (k >= 4)
	{
		if (check_rgb(&rgb, conf_map + 1))
			return (-1);
		mlx->sprite[k].color = shift_color(rgb);
	}
	return (0);
}

int	check_config(t_mlx *mlx, char **conf_map)
{
	int	i;
	int	k;
	int	*rgb;

	k = 0;
	i = 0;
	rgb = (int *)malloc(sizeof(int) * 3);
	if (rgb == NULL)
		return (0);
	while (conf_map[i])
	{
		k = check_element(conf_map[i]);
		if (check_tex_rgb(mlx, conf_map[i], rgb, k))
			return (-1);
		i++;
	}
	free(rgb);
	return (0);
}
