/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:27:25 by jmarinho          #+#    #+#             */
/*   Updated: 2024/05/29 11:54:42 by jmarinho         ###   ########.fr       */
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

// Flood fill algorithm to mark reachable cells
void ft_floodfill(int x, int y, t_mlx *mlx)
{
    if (x < 0 || x >= mlx->map.x || y < 0 || y >= mlx->map.y)
        return ;
    if (mlx->map.game_map[x][y] == '1' || mlx->map.flood_map[x][y])
        return ;

    mlx->map.flood_map[x][y] = 1;

    ft_floodfill(x - 1, y, mlx);
    ft_floodfill(x + 1, y, mlx);
    ft_floodfill(x, y - 1, mlx);
    ft_floodfill(x, y + 1, mlx);
}

void    ft_copy_flood_map(t_mlx *mlx)
{
    int i;

    i = -1;
    mlx->map.flood_map = malloc((sizeof(char *) * mlx->map.x) + 1);
    if(!mlx->map.flood_map)
        ft_perror("ERROR! Malloc mlx->map.flood_map\n", mlx);
    while (++i < mlx->map.x)
            mlx->map.flood_map[i] = strdup(mlx->map.game_map[i]);
    mlx->map.flood_map[i] = NULL;
}

void    ft_check_with_flood_fill(t_mlx *mlx)
{
    int i;
    int j;

    i = -1;
    j = -1;
    ft_copy_flood_map(mlx);
    // Flood fill from the boundaries
    printf("rows %i\ncols %i\n", mlx->map.x, mlx->map.y);
    while (++i < mlx->map.x)
    {
        ft_floodfill(i, 0, mlx);//coluna lado esquerdo
        ft_floodfill(i, mlx->map.y - 1, mlx);//coluna lado direito
        #//TODO cheak se nao e mlx->map.y - 2 por conta do '\0' e do '\n'
    }
    while(++j < mlx->map.y)
    {
        ft_floodfill(0, j, mlx);//primeira linha
        ft_floodfill(mlx->map.x - 1, j, mlx);//ultima linha
    }

    // Check if any internal space is not visited
    i = -1;
    while (++i < mlx->map.x)
    {
        j = -1;
        while (++j < mlx->map.y)
        {
            if ((mlx->map.game_map[i][j] == '0' || mlx->map.game_map[i][j] == 'N' || mlx->map.game_map[i][j] == 'S'
                || mlx->map.game_map[i][j] == 'E' || mlx->map.game_map[i][j] == 'W') && !mlx->map.flood_map[i][j])
                return ;
                //return (EXIT_SUCCESS); // The map is closed
        }
    }
    ft_perror("ERROR\nMap is not closed\n", mlx); // The map is not closed
    //return (EXIT_FAILURE); // The map is not closed
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
                    && mlx->map.game_map[i][k] != ' ' && mlx->map.game_map[i][k] != '\t')
                ft_perror("ERROR\nInvalid characters on game map\n", mlx);
        }  
    }
}

void    ft_check_game_map(t_mlx *mlx)
{   
    #//TODO fazer checkagens ao mapa
    //The map must be closed/surrounded by walls, if not the program must return an error
    //check for invalids chars in map
    //print_map(mlx->map.game_map);
    ft_check_invalid_chars(mlx);
    ft_get_rows(mlx);
    ft_get_cols(mlx);
    ft_check_with_flood_fill(mlx);
}
