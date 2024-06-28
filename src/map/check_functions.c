/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:17 by rumachad          #+#    #+#             */
/*   Updated: 2024/06/28 16:02:01 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_element(t_mlx *mlx, t_sprite *sprite, char *conf_line)
{
	if (check_path(conf_line + 2))
		return (1);
	*sprite = xpm_to_image(mlx,
			(conf_line + 2) + (advance_space(conf_line + 2)));
	return (0);
}

int	check_fc(t_sprite *sprite, int **rgb, char *conf_line)
{
	if (check_rgb(rgb, conf_line))
		return (1);
	sprite->color = shift_color(*rgb);
	return (0);
}

int	check_rgb(int **cc, char *line)
{
	char	**rgb;
	int		i;

	i = 0;
	line += advance_space(line);
	rgb = ft_split(line, ',');
	while (rgb[i])
	{
		cc[0][i] = ft_atoi(rgb[i]);
		if (!color(cc[0][i]))
			break;
		i++;
	}
	ft_free_dp((void **)rgb);
	if (i == 3)
		return (0);
	return (-1);
}

int	check_path(char *line)
{
	int	fd;

	line += advance_space(line);
	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	line += 1;
	if (ft_strncmp(ft_strchr(line, '.'), ".xpm", 5))
		return (-1);
	return (0);
}

int	check_config(t_mlx *mlx, char **conf_map)
{
	int	i;
	int	ret;
	int	*rgb;

	i = 0;
	rgb = (int *)malloc(sizeof(int) * 3);
	if (rgb == NULL)
		return (-1);
	while (conf_map[i])
	{
		if (i >= 0 && i < 4)
			ret = check_element(mlx, &mlx->sprite[i], conf_map[i]);
		else
			ret = check_fc(&mlx->sprite[i], &rgb, conf_map[i]);
		if (ret == 1)
			return (-1);
		i++;
	}
	free(rgb);
	return (0);
}
