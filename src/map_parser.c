/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:20:48 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/18 14:30:43 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_parser(t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("map.cub", O_WRONLY);

	line = get_next_line(fd);
	while (line)
	{
		while (line[i])
			draw_map(line[i++]);
		free(line);
		line = get_next_line(fd);
	}
}

/* void	draw_map(char c)
{
	if (c == 1)
		
		
} */