/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:22:16 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/26 17:27:13 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "vector2D.h"
# include <assert.h>
# include <stdbool.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LARROW 65361
# define RARROW 65363
# define FOV 90

# define WIDTH 500
# define HEIGHT 700
# define SPRITE_PIXEL 64

# define PI 3.14159265359
# define GREEN 	0x0000FF00

# define SPEED 0.1

typedef struct s_player
{
	t_v2D	pos;
	t_v2D	direction;
	t_v2D	plane;
}	t_player;

typedef struct s_map
{
	int		x;
	int		y;
	char	**game_map;

}	t_map;

typedef struct s_sprite
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void		*lib;
	void		*window;
	t_sprite	sprite[1];
	t_player	player;
	t_map		map;
	t_image		img;
}	t_mlx;

//Raycast
void		ft_grua(t_mlx *mlx);

// Update
int			update(t_mlx *mlx);

//Render
int			render(t_mlx *mlx);

// Map
void		map_draw(t_mlx *mlx);
t_map		init_map(char *map_name);

// Image
void		pixel_put(t_image *img, int pixelX, int pixelY);
t_sprite	xpm_to_image(t_mlx *mlx, char *texture);
void		image_to_window(t_mlx *mlx, void *img_ptr, int x, int y);

// Events
int			handle_keyPress(int keycode, t_mlx *mlx);
int			handle_keyRelease(int keycode, t_mlx *mlx);

void		close_game(t_mlx *mlx);

#endif