/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_content_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:01:29 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 14:21:07 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

char	*begining_of_map(char *line, char *set)
{
	int	i;
	int	k;

	i = 0;
	while (line[i])
	{
		k = 0;
		while (set[k])
		{
			if (line[i] == set[k])
				return (&line[i]);
			k++;
		}
		i++;
	}
	return (NULL);
}

bool	check_lines(char *set, char *line, t_map *map)
{
	int	i;
	int	k;

	i = 0;
	while (line[i])
	{
		k = 0;
		while (set[k])
		{
			if (line[i] != set[k])
				k++;
			else
			{
				if (line[i] == 'N' || line[i] == 'W'
					|| line[i] == 'S' || line[i] == 'E')
					map->player_flag += 1;
				break ;
			}
		}
		if (set[k] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	game_map_helper(char *trimed_line, t_map *map, int j)
{
	if (!check_lines("01NEWSHPDCedp ", map->game_map[j], map))
	{
		free(trimed_line);
		map->game_map[++j] = 0;
		return (1);
	}
	return (0);
}

int	get_game_map(t_map *map, char **full_map, int i)
{
	char	*trimed_line;
	int		j;

	j = 0;
	trimed_line = NULL;
	while (full_map[++i])
	{
		trimed_line = ft_strtrim(full_map[i], "\n");
		if (!trimed_line)
			return (-1);
		else
		{
			map->game_map[j] = ft_strdup(trimed_line);
			if (game_map_helper(trimed_line, map, j))
				return (-1);
			if ((int)ft_strlen(map->game_map[j]) > map->width)
				map->width = ft_strlen(map->game_map[j]);
			j++;
		}
		free(trimed_line);
	}
	map->game_map[j] = 0;
	if (map->player_flag == 0 || map->player_flag > 1)
		return (-1);
	return (j);
}

int	create_content_map(t_map *map, char **full_map, int after, int len)
{
	int		i;
	int		j;

	i = after;
	if (full_map[i] && full_map[i][0] != '\n')
		return (-1);
	j = 0;
	map->game_map = malloc(sizeof(char *) * (len - after + 1));
	j = get_game_map(map, full_map, i);
	return (j);
}
