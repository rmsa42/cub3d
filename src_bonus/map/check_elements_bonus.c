/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:17 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/09 14:35:21 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	is_number(char *line)
{
	int	j;

	j = 0;
	while (line[j])
		if (ft_isdigit(line[j++]) == 0)
			return (0);
	return (1);
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

int	check_element(t_mlx *mlx, t_sprite *sprite, char *conf_map)
{
	if (check_path((conf_map + 2) + advance_space(conf_map + 2)))
		return (1);
	*sprite = xpm_to_image(mlx, (conf_map + 2)
			+ advance_space(conf_map + 2));
	return (0);
}
