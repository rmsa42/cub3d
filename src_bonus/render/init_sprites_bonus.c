/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:38:56 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_sprite	xpm_to_image(t_mlx *mlx, char *texture)
{
	t_sprite	sprite;
	t_image		img;

	img.img_ptr = mlx_xpm_file_to_image(mlx->lib, texture,
			&sprite.width, &sprite.height);
	if (img.img_ptr == NULL)
		print_error("Invalid Sprite\n", EXIT_FAILURE, mlx);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (img.addr == NULL)
		print_error("Invalid Sprite address\n", EXIT_FAILURE, mlx);
	sprite.img = img;
	return (sprite);
}

void	init_sprite3(t_mlx *mlx, t_sprite *sprite)
{
	sprite[DYING3] = xpm_to_image(mlx, "sprites/char_sprites/dying3.xpm");
	sprite[DYING4] = xpm_to_image(mlx, "sprites/char_sprites/dying4.xpm");
	sprite[DYING5] = xpm_to_image(mlx, "sprites/char_sprites/dying5.xpm");
	sprite[DYING6] = xpm_to_image(mlx, "sprites/char_sprites/dying6.xpm");
	sprite[DYING7] = xpm_to_image(mlx, "sprites/char_sprites/dying7.xpm");
	sprite[COINS1] = xpm_to_image(mlx, "sprites/coins.xpm");
	sprite[COINS2] = xpm_to_image(mlx, "sprites/coins2.xpm");
	sprite[COINS3] = xpm_to_image(mlx, "sprites/coins3.xpm");
	sprite[COINS4] = xpm_to_image(mlx, "sprites/coins4.xpm");
	sprite[COINS5] = xpm_to_image(mlx, "sprites/coins5.xpm");
	sprite[COLLEC] = xpm_to_image(mlx, "sprites/collec.xpm");
	sprite[WIN_GAME] = xpm_to_image(mlx, "sprites/win_game.xpm");
	sprite[HP_COLLECT1] = xpm_to_image(mlx, "sprites/hp_collect1.xpm");
	sprite[END_DOOR1] = xpm_to_image(mlx, "sprites/end_door/end_door.xpm");
	sprite[END_DOOR2] = xpm_to_image(mlx, "sprites/end_door/end_door1.xpm");
	sprite[END_DOOR3] = xpm_to_image(mlx, "sprites/end_door/end_door2.xpm");
}

void	init_sprite2(t_mlx *mlx, t_sprite *sprite)
{
	sprite[CHARACTER7] = xpm_to_image(mlx,
			"sprites/char_sprites/character7.xpm");
	sprite[CHARACTER8] = xpm_to_image(mlx,
			"sprites/char_sprites/character8.xpm");
	sprite[HP1] = xpm_to_image(mlx, "sprites/char_sprites/hp.xpm");
	sprite[HP2] = xpm_to_image(mlx, "sprites/char_sprites/hp2.xpm");
	sprite[HP3] = xpm_to_image(mlx, "sprites/char_sprites/hp3.xpm");
	sprite[HP4] = xpm_to_image(mlx, "sprites/char_sprites/hp4.xpm");
	sprite[ATTACK1] = xpm_to_image(mlx, "sprites/char_sprites/attack.xpm");
	sprite[ATTACK2] = xpm_to_image(mlx, "sprites/char_sprites/attack1.xpm");
	sprite[ATTACK3] = xpm_to_image(mlx, "sprites/char_sprites/attack2.xpm");
	sprite[ATTACK4] = xpm_to_image(mlx, "sprites/char_sprites/attack3.xpm");
	sprite[ATTACK5] = xpm_to_image(mlx, "sprites/char_sprites/attack4.xpm");
	sprite[ATTACK6] = xpm_to_image(mlx, "sprites/char_sprites/attack5.xpm");
	sprite[ATTACK7] = xpm_to_image(mlx, "sprites/char_sprites/attack6.xpm");
	sprite[ATTACK8] = xpm_to_image(mlx, "sprites/char_sprites/attack7.xpm");
	sprite[ENEMY1] = xpm_to_image(mlx, "sprites/enemy/enemy2.xpm");
	sprite[ENEMY2] = xpm_to_image(mlx, "sprites/enemy/enemy3.xpm");
	sprite[ENEMY3] = xpm_to_image(mlx, "sprites/enemy/enemy4.xpm");
	sprite[ENEMY4] = xpm_to_image(mlx, "sprites/enemy/enemy_down.xpm");
	sprite[ENEMY_DOWN] = xpm_to_image(mlx, "sprites/enemy/enemy5.xpm");
	sprite[ENEMY5] = xpm_to_image(mlx, "sprites/enemy/enemy6.xpm");
	sprite[END_GAME] = xpm_to_image(mlx, "sprites/end_game.xpm");
	sprite[DYING1] = xpm_to_image(mlx, "sprites/char_sprites/dying.xpm");
	sprite[DYING2] = xpm_to_image(mlx, "sprites/char_sprites/dying2.xpm");
}

void	init_sprite(t_mlx *mlx, char **conf_map, t_sprite *sprite)
{
	check_conf(mlx, conf_map, sprite);
	sprite[DOOR1] = xpm_to_image(mlx, "sprites/door.xpm");
	sprite[OPEN_DOOR1] = xpm_to_image(mlx, "sprites/open.xpm");
	sprite[OPEN_DOOR2] = xpm_to_image(mlx, "sprites/open2.xpm");
	sprite[OPEN_DOOR3] = xpm_to_image(mlx, "sprites/open3.xpm");
	sprite[OPEN_DOOR4] = xpm_to_image(mlx, "sprites/open4.xpm");
	sprite[OPEN_DOOR5] = xpm_to_image(mlx, "sprites/open5.xpm");
	sprite[OPEN_DOOR6] = xpm_to_image(mlx, "sprites/open6.xpm");
	sprite[BALL1] = xpm_to_image(mlx, "sprites/ball.xpm");
	sprite[BALL2] = xpm_to_image(mlx, "sprites/ball2.xpm");
	sprite[CHARACTER1] = xpm_to_image(mlx,
			"sprites/char_sprites/character.xpm");
	sprite[CHARACTER2] = xpm_to_image(mlx,
			"sprites/char_sprites/character2.xpm");
	sprite[CHARACTER3] = xpm_to_image(mlx,
			"sprites/char_sprites/character3.xpm");
	sprite[CHARACTER4] = xpm_to_image(mlx,
			"sprites/char_sprites/character4.xpm");
	sprite[CHARACTER5] = xpm_to_image(mlx,
			"sprites/char_sprites/character5.xpm");
	sprite[CHARACTER6] = xpm_to_image(mlx,
			"sprites/char_sprites/character6.xpm");
	init_sprite2(mlx, sprite);
	init_sprite3(mlx, sprite);
}
