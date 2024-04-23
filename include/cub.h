/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:22:16 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/23 11:29:54 by rumachad         ###   ########.fr       */
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

# define GREEN 	0x0000FF00

# define DELTA 0.001

typedef struct s_player
{
	t_v2D	pos;
	t_v2D	movement;
	t_v2D	direction;
	float	angle;
}	t_player;

typedef	struct	s_map
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

typedef struct s_mlx
{
	void		*lib;
	void		*window;
	t_sprite	sprite[2];
	t_player	player;
	t_map		map;
}	t_mlx;

//Raycast
void	ft_grua(t_mlx *mlx);

// Update
int	update(t_mlx *mlx);

//Render
int	render(t_mlx *mlx);

// Map
void	map_draw(t_mlx *mlx);
t_map	init_map(char *map_name);

// Image
t_sprite	xpm_to_image(t_mlx *mlx, char *texture);
void		image_to_window(t_mlx *mlx, t_sprite sprite, double x, double y);

// Events
int		handle_keyPress(int keycode, t_mlx *mlx);
int		handle_keyRelease(int keycode, t_mlx *mlx);

void	close_game(t_mlx *mlx);

#endif