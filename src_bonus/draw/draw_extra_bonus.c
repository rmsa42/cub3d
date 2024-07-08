/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_extra_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:53:20 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/05 13:24:10 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_hearts(t_image *img, t_sprite *sprites, int spr_index)
{
	t_v2D	sprite_pos;

	sprite_pos = (t_v2D){20 * WIDTH / 800, HEIGHT - (175 * HEIGHT / 600)};
	draw_hud(img, &sprites[spr_index], sprite_pos);
}

void	draw_coins(t_image *img, t_sprite *sprites, int spr_index)
{
	t_v2D	sprite_pos;

	sprite_pos = (t_v2D){WIDTH - (150 * WIDTH / 800), -30 * HEIGHT / 600};
	draw_hud(img, &sprites[spr_index], sprite_pos);
}

void	draw_char(t_image *img, t_sprite *sprites, int spr_index)
{
	t_v2D	sprite_pos;

	sprite_pos = (t_v2D){20 * WIDTH / 800, HEIGHT - (110 * HEIGHT / 600)};
	draw_hud(img, &sprites[spr_index], sprite_pos);
}

void	end_game_screen(t_image *img, t_sprite *sprites, int spr_index)
{
	t_v2D	sprite_pos;

	sprite_pos = (t_v2D){(WIDTH / 2) - (SPRITE_SIZE * 800) / (double)WIDTH,
		HEIGHT / 2};
	draw_screen(img, &sprites[END_GAME]);
	draw_hud(img, &sprites[spr_index], sprite_pos);
}

void	end_game(t_mlx *mlx)
{
	update_animations(mlx);
	if (mlx->game_state == DIED_STATE)
		end_game_screen(&mlx->img, mlx->sprite, mlx->spr_character_index);
	else if (mlx->game_state == WIN_STATE)
		draw_screen(&mlx->img, &mlx->sprite[WIN_GAME]);
}
