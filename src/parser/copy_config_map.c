/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_config_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:48:23 by jmarinho          #+#    #+#             */
/*   Updated: 2024/05/09 14:48:07 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//#DESCARTAR ESTES FICHEIROS E FAZER DE NOVO
/*
	PARSER DO MAPA

	CUIDADOS A TER:
		-NAO PODE TER COORDENADAS REPETIDAS
		-PATHS TEM QUE SER VALIDOS (/bin/sh s/wall.xpm nao e valido)
		-TEM QUE TER TODAS AS CONFIGS (6) PARA SER VALIDO
	
	*/

void	ft_check_all_config_flags(t_mlx *mlx)
{
	if (mlx->map.NO_flag == true && mlx->map.SO_flag == true && mlx->map.EA_flag == true
		&& mlx->map.WE_flag == true && mlx->map.F_flag == true && mlx->map.F_flag == true)
		return ;
	else
		ft_perror("ERROR\nNot all necessary map configs are defined", mlx);
}

void	ft_check_for_configs(t_mlx *mlx, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && mlx->map.NO_flag == false)
	{
		mlx->map.config_map[NO] = line;
		mlx->map.NO_flag = true;
	}
	else if (line[0] == 'S' && line[1] == 'O' && mlx->map.SO_flag == false )
	{
		mlx->map.config_map[SO] = line;
		mlx->map.SO_flag = true;
	}
	else if (line[0] == 'E' && line[1] == 'A' && mlx->map.EA_flag == false)
	{
		mlx->map.config_map[EA] = line;
		mlx->map.EA_flag = true;
	}
	else if (line[0] == 'W' && line[1] == 'E' && mlx->map.WE_flag == false)
	{
		mlx->map.config_map[WE] = line;
		mlx->map.WE_flag = true;
	}
	else if (line[0] == 'F' && mlx->map.F_flag == false)
	{
		mlx->map.config_map[F] = line;
		mlx->map.F_flag = true;
	}
	else if (line[0] == 'C' && mlx->map.C_flag == false)
	{
		mlx->map.config_map[C] = line;
		mlx->map.C_flag = true;
	}
	else if (line[0] == '1')//comecou o mapa
		ft_check_all_config_flags(mlx);
	else
		ft_perror("ERROR\nInvalid or repeated config char detected", mlx);
}

void	ft_copy_config_map(t_mlx *mlx)
{
	char	*line;
	char	*clean_line;
	int	i;
	int k;
	int	fd;

	//#TODO usar um array de tamanho 6 para guardar as coordenadas
	//#TODO usar flgs para saber se aquela coordenada ja foi guardada ou nao
	//#TODO check se tem todas as flags a ẗrue¨
	
	fd = open(mlx->file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error\nCouldn't open requested file.", mlx);
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		k = -1;
		if(!line || line[0] == '\n')
		{
			line = get_next_line(fd);
			continue;
		}
		clean_line = malloc(sizeof(char) * ft_strlen(line) + 1);
		if (!clean_line)
			ft_perror ("ERROR\nMalloc for clean_line failed", mlx);
		while (line && line[++i])
		{
			if ((line[i] != ' ' && line[i] != '\t'))
				clean_line[++k] = line[i];
		}
		//clean_line[k] = '\n';
		clean_line[k + 1] = '\0';
		ft_check_for_configs(mlx, clean_line);
		//free (clean_line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	/*if (!mlx->map.config_map)
		ft_perror ("ERROR\nConfig_map non existing", mlx);*/
}
