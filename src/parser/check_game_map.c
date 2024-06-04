/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:27:25 by jmarinho          #+#    #+#             */
/*   Updated: 2024/06/04 14:13:14 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    ft_get_rows(t_mlx *mlx)
{
    int i;

    i = -1;
    mlx->map.x = 0;
    if (!mlx->map.game_map)
        return ;
    while (mlx->map.game_map[++i])
        mlx->map.x++;
}

void    ft_get_cols(t_mlx *mlx)
{
    int i;

    i = -1;
    mlx->map.y = 0;
    if (!mlx->map.game_map)
        return ;
    while (mlx->map.game_map[++i])
    {
        if ((int)ft_strlen(mlx->map.game_map[i]) > mlx->map.y)
            mlx->map.y = ft_strlen(mlx->map.game_map[i]);
    }
    mlx->map.y--;//retira o \n da contagem de colunas
}

void    ft_check_invalid_chars(t_mlx *mlx)
{
    int i;
    int k;

    
    i = -1;
    while (mlx->map.game_map[++i])
    {
        k = -1;
        while (mlx->map.game_map[i][++k])
        {
            if (mlx->map.game_map[i][k] != '0' && mlx->map.game_map[i][k] != '1' && mlx->map.game_map[i][k] != 'N' 
                && mlx->map.game_map[i][k] != 'S' && mlx->map.game_map[i][k] != 'E' && mlx->map.game_map[i][k] != 'W'
                    && mlx->map.game_map[i][k] != ' ' && mlx->map.game_map[i][k] != '\t' && mlx->map.game_map[i][k] != '\n')
                ft_perror("ERROR\nInvalid characters on game map\n", mlx);
            else if (mlx->map.game_map[i][k] == 'N' || mlx->map.game_map[i][k] == 'S' || mlx->map.game_map[i][k] == 'E'
                || mlx->map.game_map[i][k] == 'W')
            {
                mlx->map.player_count++;
                if (mlx->map.player_count != 1)
                    ft_perror("ERROR\nMore than one player on game map\n", mlx);
                else
                {
                    mlx->map.player_pos.x = i;
                    mlx->map.player_pos.y = k;
                }
            }
        }  
    }
}

/*void    ft_check_walls(t_mlx *mlx)
{
    int i;
    int j;

    i = -1;
    printf("mlx->map.y %i\n", mlx->map.y);
    printf("mlx->map.x %i\n", mlx->map.x);
    while(mlx->map.game_map[++i])
    {
        j = -1;
        while(mlx->map.game_map[i][++j])
        {
            printf("i %i\n", i);
            printf("j %i\n\n", j);
            if (mlx->map.game_map[i][j] == ' ' || mlx->map.game_map[i][j] == '\t')
                j++;
            if (((int)ft_strlen(mlx->map.game_map[i]) - 1) > j)
            {
                if (i == 0 || i == mlx->map.x - 1)
                {
                    if (mlx->map.game_map[i][j] != '1' && mlx->map.game_map[i][j] != ' '
                        && mlx->map.game_map[i][j] != '\t' && mlx->map.game_map[i][j] != '\n')
                        ft_perror("ERROR\nInvalid map (1)\n", mlx);
                    else if (mlx->map.game_map[i][j] != '1' || mlx->map.game_map[i][mlx->map.y - 1] != '1')
                        ft_perror("ERROR\nInvalid map (2)\n", mlx);
                }
                if (ft_strlen(mlx->map.game_map[i]) > ft_strlen(mlx->map.game_map[0])
                    && ft_strlen(mlx->map.game_map[j]) > ft_strlen(mlx->map.game_map[i]))
                    if (mlx->map.game_map[i][j] != '1')
                        ft_perror("ERROR\nInvalid map (3)\n", mlx);
                if (ft_strlen(mlx->map.game_map[i]) > ft_strlen(mlx->map.game_map[mlx->map.x])
                    && ft_strlen(mlx->map.game_map[j]) > ft_strlen(mlx->map.game_map[mlx->map.x]))
                    if (mlx->map.game_map[i][j] != '1')
                        ft_perror("ERROR\nInvalid map (4)\n", mlx);
            }                 
        }
        
    }
} */

void ft_flood_fill(int x, int y, t_mlx *mlx)
{
    
    if( mlx->map.flood_map[x][y] == '1')
        return ;
    else if ( mlx->map.flood_map[x][y] != '0' &&  mlx->map.flood_map[x][y] != '1' &&  mlx->map.flood_map[x][y] != 'N' && mlx->map.flood_map[x][y] != 'S'
        &&  mlx->map.flood_map[x][y] != 'E' &&  mlx->map.flood_map[x][y] != 'W')
        ft_perror("ERROR\nMap is open\n", mlx);
     mlx->map.flood_map[x][y] = '1';
    ft_flood_fill(x + 1, y,  mlx);
    ft_flood_fill(x, y + 1,  mlx);
    ft_flood_fill(x - 1, y,  mlx);
    ft_flood_fill(x, y - 1, mlx);
}

void    ft_check_walls(t_mlx *mlx)
{
    int i;

    i = -1;
    mlx->map.flood_map = malloc(sizeof(char *) * mlx->map.x);
	if (!mlx->map.flood_map) 
		ft_perror ("ERROR\nMalloc for mlx->map.flood_map failed\n", mlx);
    while(mlx->map.game_map[++i])
        mlx->map.flood_map[i] = ft_strdup(mlx->map.game_map[i]);
    mlx->map.flood_map[i] = NULL;
    ft_flood_fill(mlx->map.player_pos.x, mlx->map.player_pos.y, mlx);
}

void    ft_check_game_map(t_mlx *mlx)
{   
    #//TODO mapa sem linha branco a separar da merda
    #//TODO fazer checkagens ao mapa; walls and invalid chars
    mlx->map.player_count = 0;
    ft_check_invalid_chars(mlx);
    ft_get_rows(mlx);
    ft_get_cols(mlx);
    ft_check_walls(mlx);
 }
