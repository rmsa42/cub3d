/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:02:04 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 14:25:11 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	check_config_map2(t_map *map, char *dir, int pos)
{
	char	*swap;
	int		i;

	i = -1;
	while (map->config_map[++i])
	{
		if (ft_strncmp(map->config_map[i], dir, ft_strlen(dir)) == 0)
		{
			swap = map->config_map[pos];
			map->config_map[pos] = map->config_map[i];
			map->config_map[i] = swap;
			return (0);
		}
	}
	return (1);
}

int	check_config_map(t_map *map)
{
	if (check_config_map2(map, "NO ", 0))
		return (1);
	if (check_config_map2(map, "SO ", 1))
		return (1);
	if (check_config_map2(map, "WE ", 2))
		return (1);
	if (check_config_map2(map, "EA ", 3))
		return (1);
	if (check_config_map2(map, "F ", 4))
		return (1);
	if (check_config_map2(map, "C ", 5))
		return (1);
	return (0);
}

int	create_config_map(t_map *map, char **full_map)
{
	int		i;
	int		counter;
	char	*trimed_line;

	i = 0;
	counter = 0;
	trimed_line = NULL;
	while (full_map[i] && counter < 6)
	{
		trimed_line = ft_strtrim(full_map[i], " 	\n");
		if (!trimed_line)
			return (-1);
		else if (!ft_strlen(trimed_line))
			i++;
		else
		{
			map->config_map[counter++] = ft_strdup(trimed_line);
			i++;
		}
		free(trimed_line);
	}
	if (counter < 6)
		return (-1);
	return (i);
}

int	map_parser2(char **full_map, t_map *map, int nbr_lines)
{
	int		config_lines;

	config_lines = create_config_map(map, full_map);
	if (config_lines == -1 || map->config_map[0] == NULL)
		return (1);
	if (check_config_map(map))
		return (1);
	map->height = create_content_map(map, full_map, config_lines, nbr_lines);
	if (map->height == -1 || map->game_map[0] == NULL)
		return (1);
	return (0);
}

int	map_parser(char *map_name, t_map *map)
{
	int		fd;
	int		nbr_lines;
	char	**full_map;

	fd = 0;
	if (!ft_strnstr(map_name, ".cub", ft_strlen(map_name)))
		return (1);
	nbr_lines = calc_map_lines(fd, map_name);
	if (nbr_lines == -1)
		return (1);
	full_map = create_full_map(fd, map_name, nbr_lines);
	if (full_map == NULL)
		return (1);
	if (map_parser2(full_map, map, nbr_lines))
	{
		ft_free_dp((void **)full_map);
		return (1);
	}
	ft_free_dp((void **)full_map);
	return (0);
}
