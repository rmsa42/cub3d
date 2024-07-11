/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:17 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/09 14:44:26 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_number(char *line)
{
	int	j;

	j = 0;
	while (line[j])
		if (ft_isdigit(line[j++]) == 0)
			return (0);
	return (1);
}

int	check_element(t_mlx *mlx, t_sprite *sprite, char *conf_line)
{
	if (check_path((conf_line + 2) + advance_space(conf_line + 2)))
		return (1);
	*sprite = xpm_to_image(mlx,
			(conf_line + 2) + (advance_space(conf_line + 2)));
	return (0);
}

int	check_rgb(char *line)
{
	char	**rgb;
	int		i;
	int		ele_color;
	int		c[3];

	i = -1;
	rgb = ft_split(line, ',');
	while (rgb[++i])
	{
		if (!is_number(rgb[i]))
			break ;
		ele_color = ft_atoi(rgb[i]);
		if (color(ele_color))
			c[i] = ele_color;
		else
			break ;
	}
	ft_free_dp((void **)rgb);
	if (i != 3)
		return (-1);
	return (shift_color(c));
}

int	check_path(char *line)
{
	int		fd;
	char	*extension;

	extension = line + 1;
	extension = ft_strchr(extension, '.');
	if (!extension)
		return (-1);
	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	if (ft_strcmp((extension + ft_strlen(extension) - 4), ".xpm"))
		return (-1);
	return (0);
}

int	check_conf(t_mlx *mlx, char **conf_map, t_sprite *sprite)
{
	int	k;

	k = -1;
	while (conf_map[++k] && k < 4)
	{
		if (check_element(mlx, &sprite[k], conf_map[k]))
			print_error("Wrong Textures", EXIT_FAILURE, mlx);
	}
	mlx->f_color = check_rgb(conf_map[4] + 1 + advance_space(conf_map[4] + 1));
	mlx->c_color = check_rgb(conf_map[5] + 1 + advance_space(conf_map[5] + 1));
	if (mlx->c_color == -1 || mlx->f_color == -1)
		print_error("Wrong Colors", EXIT_FAILURE, mlx);
	return (0);
}
