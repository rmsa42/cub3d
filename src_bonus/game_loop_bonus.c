/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:49:21 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/05 11:55:37 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	update_state(t_mlx *mlx)
{
	t_player	*player;
	char		**game_map;

	game_map = mlx->map->game_map;
	player = &mlx->player;
	if (player->hp <= 0)
		mlx->game_state = DIED_STATE;
	else if (player->coins == MAX_COINS
		&& mlx->nbr_maps == mlx->iter_map)
		mlx->game_state = WIN_STATE;
	else if (player->coins == MAX_COINS
		&& game_map[(int)player->pos.y][(int)player->pos.x] == 'p')
		mlx->game_state = PORTAL_STATE;
	else
		mlx->game_state = GAME_STATE;
}

void	draw(t_mlx *mlx)
{
	mlx->img = image_buffer(mlx);
	if (mlx->game_state == GAME_STATE)
	{
		ft_crane(mlx);
		draw_sprites(mlx);
		draw_char(&mlx->img, mlx->sprite, mlx->spr_character_index);
		draw_hearts(&mlx->img, mlx->sprite, mlx->spr_hp_index);
		draw_coins(&mlx->img, mlx->sprite, mlx->spr_coins_index);
		draw_minimap(mlx);
		draw_status(mlx);
	}
	else
		end_game(mlx);
}

void	update(t_mlx *mlx)
{
	update_state(mlx);
	if (mlx->game_state == PORTAL_STATE)
	{
		free_obj_lst(mlx->objs_lst);
		mlx->objs_lst = NULL;
		free(mlx->marked_cells);
		free_config(mlx->lib, mlx->sprite);
		mlx->map++;
		mlx->iter_map++;
		check_conf(mlx, mlx->map->config_map, mlx->sprite);
		set_map(mlx);
		mlx->tile_size = 5.5 *(HEIGHT / 600);
		if (mlx->map->height > 60 || mlx->map->width > 60 || mlx->tile_size < 1)
			mlx->tile_size = 1;
	}
	else if (mlx->game_state == GAME_STATE)
	{
		update_player(mlx, &mlx->player, mlx->map);
		enemy_ray(mlx, mlx->objs_lst);
		update_sprites(mlx, &mlx->player, mlx->objs_lst);
		update_animations(mlx);
	}
}

int	game_loop(t_mlx *mlx)
{
	update_time(&mlx->current_time);
	mlx->delta = time_passed(&mlx->prev_time, &mlx->current_time);
	mlx->prev_time = mlx->current_time;
	mlx->elapsed_time = time_passed(&mlx->last_time, &mlx->current_time);
	mlx->elapsed_door = time_passed(&mlx->door_time, &mlx->current_time);
	update(mlx);
	draw(mlx);
	mlx_put_image_to_window(mlx->lib, mlx->window,
		mlx->img.img_ptr, 0, 0);
	mlx_destroy_image(mlx->lib, mlx->img.img_ptr);
	return (0);
}
