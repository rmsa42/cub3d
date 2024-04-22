/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:07:33 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/19 17:35:46 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char **clone_map(char *map_name)
{
	int		fd;
	char	*line;
	char	*map_join;
	char	**map;
	
	map_join = NULL;
	fd = open(map_name, O_RDONLY);
	assert(fd != -1);
	line = get_next_line(fd);
	while (line)
	{
		map_join = ft_strjoin_get(map_join, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(map_join, '\n');
	free(map_join);
	return (map);
}

t_map	init_map(char *map_name)
{
	t_map	map;

	map.x = 0;
	map.y = 0;
	map.map_name = map_name;
	map.game_map = clone_map(map_name);

	return (map);
}
