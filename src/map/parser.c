/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:17 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/29 22:56:06 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_element(char *line)
{
	int		i;
	char	*ele[7];

	i = 0;
	ele[0] = "NO ";
	ele[1] = "SO ";
	ele[2] = "WE ";
	ele[3] = "EA ";
	ele[4] = "F ";
	ele[5] = "C ";
	ele[6] = 0;
	while (ele[i])
	{
		if (i < 4 && !ft_strncmp(line, ele[i], 3))
			return (i);
		else if (i >= 4 && !ft_strncmp(line, ele[i], 2))
			return (i);
		i++;
	}
	return (-1);
}

int	check_rgb(char *line)
{
	char	**rgb;
	int		i;

	i = 0;
	line += advance_space(line);
	rgb = ft_split(line, ',');
	while (rgb[i])
	{
		if (!color(ft_atoi(rgb[i])))
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
	return (0);
}

int	check_row(char *line)
{
	
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	i = check_element(line);
	if (i >= 0 && i < 4)
		i = check_path(line + 2);
	else if (i >= 4)
		i = check_rgb(line + 2);
	if (i == -1)
		return (1);
	return (0);
}

int	parser_map(t_map *map)
{
	int i;

	i = 0;
	print_map(map->game_map);
	printf("\n");
	while (map->game_map[i])
	{
		if (check_line(map->game_map[i]))
			return (1);
		if (i == 6)
			break ;
		i++;
	}
	while (map->game_map[i])
	return (0);
}
