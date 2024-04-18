/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:22:16 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/18 14:55:39 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <assert.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_sprite
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_mlx
{
	void	*lib;
	void	*window;
}	t_mlx;

// Map Parser

// Image
void	*xpm_to_image(t_mlx *mlx);

int		handle_event(int keycode, t_mlx *mlx);
void	close_game(t_mlx *mlx);

#endif