/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:29:45 by jmarinho          #+#    #+#             */
/*   Updated: 2024/06/05 17:09:52 by jmarinho         ###   ########.fr       */
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

# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define F 	4
# define C 	5

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LARROW 65361
# define RARROW 65363

# define HEIGHT 600
# define WIDTH 800
# define FOV 90
# define SPRITE_SIZE 64

# define PI 3.14159265359

# define SPEED 0.02

typedef struct s_player
{
	t_v2D	pos;
	t_v2D	direction;
	t_v2D	plane;
	t_v2D	movement;
	double	fov;
	double	angle;
}	t_player;

typedef struct x_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		x;
	int		y;
	int		total_lines;
	int		lines_to_map;
	int		player_count;
	t_pos	player_pos;
	char	**file_map;
	char	*config_map[6];
	char	**game_map;
	char	**flood_map;
	bool	no_flag;
	bool	so_flag;
	bool	ea_flag;
	bool	we_flag;
	bool	f_flag;
	bool	c_flag;
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
}	t_sprite;

typedef struct s_ray
{
	t_v2D	dir;
	t_v2D	delta;
	t_v2D	side_d;
	t_v2D	step;
}	t_ray;

typedef struct s_mlx
{
	char		*file;
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
	int			tex_x;
	int			side;
	double		line_height;
	double		scale;
	double		tex_pos;
	int			sprite_index;
}	t_mlx;

t_player	init_player(double x, double y, char tile);
//Raycast
void		ft_grua(t_mlx *mlx);
void		draw_texture(t_mlx *mlx, int x);

// Update
void		update(t_player *player, t_map *map);

//Render
int			render(t_mlx *mlx);

// Map
void		map_draw(t_mlx *mlx);
t_map		init_map(char *map_name);
void		ft_check_b4_init(int ac, char **av, t_mlx *mlx);
void		ft_check_game_map(t_mlx *mlx);
void		ft_copy_config_map(t_mlx *mlx);
void		ft_copy_game_map(t_mlx *mlx);
int			ft_check_all_config_flags(t_mlx *mlx);
void		ft_count_map_lines(t_mlx *mlx);
int			ft_check_if_line_is_blank(char *line);

// Parser (MAP)
int			parser_map(t_mlx *mlx);
int			color(int nbr);
int			advance_space(char *line);

void		print_map(char **map);
int			ft_check_filename(t_mlx *mlx);
void		ft_read_file_and_copy_map(t_mlx *mlx);
int			ft_count_lines(t_mlx *mlx);

// Image
void		pixel_put(t_image *img, int pixelX, int pixelY, int color);
int			pixel_get(t_image *img, int pixel_x, int pixel_y);
t_sprite	xpm_to_image(t_mlx *mlx, char *texture);

// Events
int			handle_keyPress(int keycode, t_mlx *mlx);
int			handle_keyRelease(int keycode, t_player *player);

void		close_game(t_mlx *mlx);
void		ft_perror(char *msg, t_mlx *mlx);

#endif