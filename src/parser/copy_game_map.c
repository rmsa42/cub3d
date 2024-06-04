/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:35:11 by jmarinho          #+#    #+#             */
/*   Updated: 2024/06/04 16:52:43 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_if_line_is_blank(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

void	ft_copy_game_map(t_mlx *mlx)
{
	int		i;
	int		fd;
	char	*line;

	mlx->map.empty_line_flag = 0;
	mlx->map.game_map = malloc((sizeof(char *) * mlx->map.total_lines) + 1);
	if (!mlx->map.game_map)
		ft_perror ("ERROR\nMalloc for mlx->map.game_map failed\n", mlx);
	fd = open(mlx->file, O_RDONLY);
	if (fd < 0)
		ft_perror("ERROR\nCouldn't open requested file\n", mlx);
	i = 0;
	while (i++ <= mlx->map.lines_to_map || !line)
		line = get_next_line(fd);
	i = -1;
	while (line)
	{
		if (!line || ft_check_if_line_is_blank(line))
		{
			free (line);
			line = get_next_line(fd);
			continue ;
		}
		mlx->map.game_map[++i] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
	}
	mlx->map.game_map[i + 1] = NULL;
	close(fd);
}
