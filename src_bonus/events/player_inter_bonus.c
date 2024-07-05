/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_inter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:59:50 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	interact_door(char **game_map, t_player *player)
{
	t_type	tile;
	int		check_x;
	int		check_y;

	tile = get_next_tile(game_map, player);
	check_x = (int)(player->pos.x + player->direction.x);
	check_y = (int)(player->pos.y + player->direction.y);
	if (tile == DOOR)
		game_map[check_y][check_x] = 'd';
	else if (tile == DOOR_OPEN)
		game_map[check_y][check_x] = 'D';
	if (tile == END_DOOR_STATE2)
		game_map[check_y][check_x] = 'p';
}

t_type	get_next_tile(char **game_map, t_player *player)
{
	int		check_x;
	int		check_y;

	check_x = (int)(player->pos.x + player->direction.x);
	check_y = (int)(player->pos.y + player->direction.y);
	if (game_map[check_y][check_x] == 'D')
		return (DOOR);
	else if (game_map[check_y][check_x] == 'p')
		return (END_DOOR_STATE3);
	else if (game_map[check_y][check_x] == 'P' && player->coins == 4)
		return (END_DOOR_STATE2);
	else if (game_map[check_y][check_x] == 'P')
		return (END_DOOR_STATE);
	else if (game_map[check_y][check_x] == 'd')
		return (DOOR_OPEN);
	else if (game_map[check_y][check_x] == '1')
		return (WALL);
	return (FLOOR);
}
