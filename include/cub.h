/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:22:16 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/19 16:38:41 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "vector2D.h"
# include <assert.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define DELTA 0.10

typedef struct s_player
{
	t_v2D	pos;
	
}	t_player;

typedef	struct	s_map
{
	int		x;
	int		y;
	char	**game_map;
	char	*map_name;
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
void	ft_grua(t_player *player);

//Render
int	render(t_mlx *mlx);

// Map
void	map_draw(t_mlx *mlx);
t_map	init_map(char *map_name);

// Image
t_sprite	xpm_to_image(t_mlx *mlx, char *texture);
void		image_to_window(t_mlx *mlx, t_sprite sprite, double x, double y);

int		handle_event(int keycode, t_mlx *mlx);
void	close_game(t_mlx *mlx);

#endif