/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:22:16 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/02 17:47:33 by rumachad         ###   ########.fr       */
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

# define HEIGHT 600
# define WIDTH 800
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

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_sprite
{
	t_image	img;
	int		height;
	int		width;
	int		rgb[3];
}	t_sprite;

typedef struct s_ray
{
	t_v2D	pos;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
}	t_ray;

typedef struct s_mlx
{
	void		*lib;
	void		*window;
	t_sprite	sprite[6];
	t_player	player;
	t_map		map;
	t_image		img;
	t_ray		ray;
	double		camera;
	double		angle;
	int			f_color;
	int			c_color;
}	t_mlx;


t_player	init_player(double x, double y, char tile);
//Raycast
void		ft_grua(t_mlx *mlx);

// Update
int			update(t_mlx *mlx);

//Render
int			render(t_mlx *mlx);

// Map
void		map_draw(t_mlx *mlx);
t_map		init_map(char *map_name);

// Parser (MAP)
int			parser_map(t_mlx *mlx);
int			color(int nbr);
int			advance_space(char *line);
void		print_map(char **map);

// Image
void		pixel_put(t_image *img, int pixelX, int pixelY, int color);
int			pixel_get(t_image *img, int pixel_x, int pixel_y);
t_sprite	xpm_to_image(t_mlx *mlx, char *texture);
void		image_to_window(t_mlx *mlx, void *img_ptr, int x, int y);
int			shift_color(t_sprite sprite);

// Events
int			handle_keyPress(int keycode, t_mlx *mlx);

void		close_game(t_mlx *mlx);

#endif