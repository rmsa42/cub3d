/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:17 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/29 17:58:06 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	advance_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] == 32)
		i++;
	return (i);
}

int	check_texture(char *line)
{
	int		i;
	char	*texture;
	char	*ar;

	i = 0;
	texture = "NSWE";
	ar = "OOEA";
	while (texture[i])
	{
		if (line[0] == texture[i])
		{
			if (line[1] == ar[i] && line[2] == ' ')
			{
				printf("Passed\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_path(char *line)
{
	int	fd;

	line += advance_space(line);
	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_line(char *line, int flag)
{
	if (flag == 0)
	{
		if (check_texture(line))
			return (1);
		if (check_path(line + 2))
			return (1);
	}
	return (0);
}

void	print_map(char **map)
{
	int i = 0;

	while (map[i])
		printf("%s\n", map[i++]);
}

void	parser_map(t_map *map)
{
	int i;

	i = 0;
	print_map(map->game_map);
	printf("\n");
	while (map->game_map[i])
	{
		if (check_line(map->game_map[i], 0))
			break;
		i++;
	}
	exit(0);
}