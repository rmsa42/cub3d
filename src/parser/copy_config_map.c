/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_config_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:48:23 by jmarinho          #+#    #+#             */
/*   Updated: 2024/06/04 17:31:19 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_all_config_flags(t_mlx *mlx)
{
	if (mlx->map.no_flag == true && mlx->map.so_flag == true
		&& mlx->map.ea_flag == true && mlx->map.we_flag == true
		&& mlx->map.f_flag == true && mlx->map.c_flag == true)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	ft_check_for_configs(t_mlx *mlx, char *line)
{
	if (!line || line[0] == '\0')
		return ;
	if (line[0] == 'N' && line[1] == 'O' && mlx->map.no_flag == false)
	{
		mlx->map.config_map[NO] = ft_strdup(line + 2);
		mlx->map.no_flag = true;
	}
	else if (line[0] == 'S' && line[1] == 'O' && mlx->map.so_flag == false)
	{
		mlx->map.config_map[SO] = ft_strdup(line + 2);
		mlx->map.so_flag = true;
	}
	else if (line[0] == 'E' && line[1] == 'A' && mlx->map.ea_flag == false)
	{
		mlx->map.config_map[EA] = ft_strdup(line + 2);
		mlx->map.ea_flag = true;
	}
	else if (line[0] == 'W' && line[1] == 'E' && mlx->map.we_flag == false)
	{
		mlx->map.config_map[WE] = ft_strdup(line + 2);
		mlx->map.we_flag = true;
	}
	else if (line[0] == 'F' && mlx->map.f_flag == false)
	{
		mlx->map.config_map[F] = ft_strdup(line + 1);
		mlx->map.f_flag = true;
	}
	else if (line[0] == 'C' && mlx->map.c_flag == false)
	{
		mlx->map.config_map[C] = ft_strdup(line + 1);
		mlx->map.c_flag = true;
	}
	else
		ft_perror("ERROR\nWrong configuration detected\n", mlx);
}

void	ft_copy_config_map(t_mlx *mlx)
{
	char	*line;
	char	*clean_line;
	int		i;
	int		k;
	int		fd;

	fd = open(mlx->file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error\nCouldn't open requested file\n", mlx);
	line = get_next_line(fd);
	mlx->map.lines_to_map++;
	while (line)
	{
		i = -1;
		k = -1;
		if (!line || line[0] == '\n')
		{
			free (line);
			line = get_next_line(fd);
			mlx->map.lines_to_map++;
			continue ;
		}
		clean_line = malloc(sizeof(char) * ft_strlen(line));
		if (!clean_line)
		{
			if (line)
				free (line);
			ft_perror ("ERROR\nMalloc for clean_line failed\n", mlx);
		}
		clean_line[0] = '\0';
		while (line && line[++i])
		{
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				clean_line[++k] = line[i];
		}
		if (k == -1)
			k = 0;
		clean_line[k + 1] = '\0';
		ft_check_for_configs(mlx, clean_line);
		if (line)
			free (line);
		free (clean_line);
		if (!ft_check_all_config_flags(mlx))
			break ;
		line = get_next_line(fd);
		mlx->map.lines_to_map++;
	}
	while (line)
		line = get_next_line(fd);
	free (line);
	close(fd);
}
