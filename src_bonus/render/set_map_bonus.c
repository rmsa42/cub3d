/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:20:48 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 16:19:17 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_player	init_player(double x, double y, char tile)
{
	t_player	player;

	player.pos = (t_v2D){x, y};
	if (tile == 'N')
		player.direction = (t_v2D){0, -1};
	else if (tile == 'S')
		player.direction = (t_v2D){0, 1};
	else if (tile == 'W')
		player.direction = (t_v2D){-1, 0};
	else if (tile == 'E')
		player.direction = (t_v2D){1, 0};
	player.movement = (t_v2D){0, 0};
	player.pitch = 0;
	player.plane = multiply_vector(perp_vector(player.direction), \
		(double)FOV / 90);
	player.angle = 0;
	player.coins = 0;
	player.damaged = 0;
	player.healed = 0;
	player.shoot_anim = false;
	player.shoot = false;
	player.ball_node = NULL;
	player.mouse = false;
	player.hp = 100;
	return (player);
}

t_objs	*init_obj(t_v2D pos, int spr_index, int hp, t_type type)
{
	t_objs	*obj;

	obj = ft_calloc(1, sizeof(t_objs));
	obj->spr_index = spr_index;
	obj->type = type;
	obj->pos = pos;
	obj->hp = hp;
	obj->state = 0;
	obj->elapsed_time = 0;
	update_time(&obj->last_time);
	return (obj);
}

int	map_info(t_mlx *mlx, char *tile, int x, int y)
{
	t_list		*node;

	node = NULL;
	if ((*tile == 'N' || *tile == 'S' || *tile == 'W' || *tile == 'E'))
	{
		mlx->player = init_player(x + 0.5, y + 0.5, *tile);
		*tile = '0';
	}
	else if (*tile == 'e')
		node = ft_lstnew((void *)init_obj((t_v2D){x + 0.5, y + 0.5}, \
			ENEMY1, 2, ENEMY));
	else if (*tile == 'C')
		node = ft_lstnew((void *)init_obj((t_v2D){x + 0.5, y + 0.5}, \
			COLLEC, 1000, COLLECT));
	else if (*tile == 'H')
		node = ft_lstnew((void *)init_obj((t_v2D){x + 0.5, y + 0.5}, \
			HP_COLLECT1, 1000, HP_COLLECT));
	if (node != NULL)
	{
		ft_lstadd_back(&mlx->objs_lst, node);
		*tile = '0';
	}
	return (0);
}

int	set_map(t_mlx *mlx)
{
	t_map		*map;

	map = mlx->map;
	mlx->marked_cells = (t_cell *)ft_calloc(map->height * map->width, \
		sizeof(t_cell));
	if (mlx->marked_cells == NULL)
		print_error("Syscall Failure\n", EXIT_FAILURE, mlx);
	while (map->game_map[map->y])
	{
		map->x = 0;
		while (map->game_map[map->y][map->x])
		{
			map_info(mlx, &map->game_map[map->y][map->x], \
				map->x, map->y);
			map->x++;
		}
		map->y++;
	}
	return (0);
}
