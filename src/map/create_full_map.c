/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_full_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:53:15 by rumachad          #+#    #+#             */
/*   Updated: 2024/06/28 11:00:13 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**cpy_map(int fd, int len)
{
	char	**map;
	char	*line;
	int		i;

	map = malloc(sizeof(char *) * (len + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	return (map);
}

int	map_nbr_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	calc_map_lines(int fd, char *map_name)
{
	int	nbr_lines;

	nbr_lines = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	nbr_lines = map_nbr_lines(fd);
	close(fd);
	return (nbr_lines);
}

char	**create_full_map(int fd, char *map_name, int nbr_lines)
{
	char	**full_map;

	full_map = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	full_map = cpy_map(fd, nbr_lines);
	close(fd);
	return (full_map);
}
