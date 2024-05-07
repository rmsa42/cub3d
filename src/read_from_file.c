/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:48:23 by jmarinho          #+#    #+#             */
/*   Updated: 2024/05/07 17:22:08 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    ft_moises(t_mlx *mlx)
{
	int	i;
	int k;

	i = -1;
	mlx->map.config_map = malloc(sizeof(char *) * 6);
	if (!mlx->map.config_map)
		ft_perror("ERROR\nMalloc for mlx->map.config_map failed", mlx);
	while (++i < 6)
		mlx->map.config_map[i] = ft_strdup(mlx->map.file_map[i]);
	mlx->map.config_map[6] = NULL;
	i = 0;
	k = 5;
	mlx->map.game_map = malloc(sizeof(char *) * mlx->map.x);
	if (!mlx->map.game_map)
		ft_perror("ERROR\nMalloc for mlx->map.game_map failed", mlx);
	while (mlx->map.file_map[++k])
		mlx->map.game_map[i++] = ft_strdup(mlx->map.file_map[k]);
	mlx->map.game_map[i] = NULL;
}

void	ft_copy_map(t_mlx *mlx, int fd)
{
	//#TODO ERROR COMPILING
	char	*line;
	char	*clean_line;
	char	*map_join;
	int	count_lines;
	int	i;
	int k;

	map_join = NULL;
	count_lines = mlx->map.x;
	mlx->map.file_map = malloc(sizeof(char *) * mlx->map.x);
	if (!mlx->map.file_map)
		ft_perror ("ERROR\nMalloc for mlx->map.file_map failed", mlx);
	while (count_lines-- >= 0)
	{
		i = -1;
		k = -1;
		line = get_next_line(fd);
		if(!line || line[0] == '\n')
			continue;
		clean_line = malloc(sizeof(char) * ft_strlen(line));
		while (line && line[++i])
		{
			if (line[i] != ' ' && line[i] != '\t')
				clean_line[++k] = line[i];
		}
		map_join = ft_strjoin_get(map_join, clean_line);
		free (line);
		free (clean_line);
	}
	close(fd);
	mlx->map.file_map = ft_split(map_join, '\n');
	free (map_join);
	if (!mlx->map.file_map)
		ft_perror ("ERROR\nFile_map non existing", mlx);
}

void	ft_get_rows(t_mlx *mlx, char *file)
{
	char	*line;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error\nCouldn't open requested file.", mlx);
	mlx->map.x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		mlx->map.x++;
	}
	close(fd);
}

void    ft_read_file_and_copy_map(char *file, t_mlx *mlx)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error\nCouldn't open requested file.", mlx);
	ft_get_rows(mlx, file);
	ft_copy_map(mlx, fd);
	ft_moises(mlx);
}
