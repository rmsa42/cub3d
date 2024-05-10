/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:20:48 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/10 17:24:15 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_player	init_player(double x, double y, char tile)
{
	t_player	player;
	int			dir;

	dir = 1;
	player.pos = (t_v2D){x, y};
	if (tile == 'N')
		player.direction = create_vector(0, -dir);
	else if (tile == 'S')
		player.direction = create_vector(0, dir);
	else if (tile == 'W')
		player.direction = create_vector(-dir, 0);
	else if (tile == 'E')
		player.direction = create_vector(dir, 0);
	player.movement = (t_v2D){0, 0};
	player.plane = perp_vector(player.direction);
	player.angle = 0.1;
	player.fov = (double)FOV / 90;
	return (player);
}

void	set_pos(t_player *player, char tile, int x, int y)
{
	if ((tile == 'N' || tile == 'S' || tile == 'W' || tile == 'E'))
		*player = init_player(x + 0.5, y + 0.5, tile);
}

void	set_map(t_map *map, t_player *player)
{
	map->y = 0;
	while (map->game_map[map->y])
	{
		map->x = 0;
		while (map->game_map[map->y][map->x])
		{
			set_pos(player, map->game_map[map->y][map->x], map->x, map->y);
			map->x++;
		}
		map->y++;
	}
}
