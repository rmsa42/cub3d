/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:49:36 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	get_color(int x, int y, t_map *map)
{
	int	color;

	if (map->game_map[y][x] == '0')
		color = GREY;
	else if (map->game_map[y][x] == 'D'
		|| map->game_map[y][x] == 'd')
		color = BLUE;
	else if (map->game_map[y][x] == 'P'
		|| map->game_map[y][x] == 'p')
		color = VIOLET;
	else if (map->game_map[y][x] == 'X')
		color = WHITE;
	else
		color = BLACK;
	return (color);
}

void	minimap_tiles(t_mlx *mlx, t_map *map, int tile_size)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < (int)ft_strlen(map->game_map[y]))
			put_tiles(mlx, x, y, tile_size);
	}
}

void	map_objs(t_mlx *mlx, int tile_size, int i, int j)
{
	t_v2D	sprite;
	t_objs	*obj;
	int		color;
	t_list	*objs_lst;

	objs_lst = mlx->objs_lst;
	while (objs_lst != NULL)
	{
		obj = (t_objs *)objs_lst->content;
		sprite = multiply_vector(obj->pos, tile_size);
		if (obj->type == ENEMY)
			color = RED;
		else if (obj->type == COLLECT)
			color = YELLOW;
		else if (obj->type == BALL)
			color = DARK_BLUE;
		else if (obj->type == HP_COLLECT)
			color = GREEN;
		pixel_put(&mlx->img, sprite.x + i, sprite.y + j, color);
		objs_lst = objs_lst->next;
	}
}

void	draw_map_sprites(t_mlx *mlx, int tile_size)
{
	t_v2D	player;
	int		sprite_size;
	int		i;
	int		j;

	sprite_size = tile_size / 2;
	i = -sprite_size;
	player = multiply_vector(mlx->player.pos, tile_size);
	while (i < sprite_size)
	{
		j = -sprite_size;
		while (j < sprite_size)
		{
			map_objs(mlx, tile_size, i, j);
			pixel_put(&mlx->img, player.x + i, player.y + j, LIGHT_BLUE);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	minimap_tiles(mlx, mlx->map, mlx->tile_size);
	draw_map_sprites(mlx, mlx->tile_size);
}
