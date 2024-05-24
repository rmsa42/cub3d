/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:34:30 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/23 11:07:35 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	color(int nbr)
{
	if (nbr >= 0 && nbr <= 255)
		return (1);
	return (0);
}

int	advance_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] == 32)
		i++;
	return (i);
}

void	print_map(char **map)
{
	int i = 0;

	while (map[i])
		printf("%s", map[i++]);
}