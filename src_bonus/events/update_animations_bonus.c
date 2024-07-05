/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_animations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:39:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	calc_char_anim(t_mlx *mlx)
{
	static int	char_anim = CHARACTER1;
	static int	i;

	if (mlx->game_state == DIED_STATE && i == 0)
	{
		char_anim = DYING1;
		i = 1;
	}
	else if (mlx->player.shoot == true && i == 0 && mlx->player.shoot_anim)
	{
		i = 1;
		char_anim = ATTACK1;
	}
	else if (mlx->elapsed_time >= 0.10 && char_anim < DYING7)
	{
		char_anim++;
		update_time(&mlx->last_time);
	}
	if (char_anim == HP1 || char_anim == ENEMY1)
	{
		mlx->player.shoot_anim = false;
		i = 0;
		char_anim = CHARACTER1;
	}
	return (char_anim);
}

void	ball_animation(t_objs *ball)
{
	static int	i;

	if (i++ >= 45)
		ball->spr_index = BALL2;
	else
		ball->spr_index = BALL1;
	if (i == 91)
		i = 0;
}

void	update_animations(t_mlx *mlx)
{
	t_player	*player;

	player = &mlx->player;
	mlx->spr_character_index = calc_char_anim(mlx);
	mlx->spr_hp_index = HP4 - (player->hp / 26);
	mlx->spr_coins_index = COINS1 + player->coins;
}
