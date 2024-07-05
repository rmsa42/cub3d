/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2D_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:17:48 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:48:01 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2D_BONUS_H
# define VECTOR2D_BONUS_H

# include <stdio.h>
# include <math.h>

typedef struct s_v2D
{
	double	x;
	double	y;
}	t_v2D;

t_v2D	add_vector(t_v2D v1, t_v2D v2);
t_v2D	minus_vector(t_v2D v1, t_v2D v2);
t_v2D	multiply_vector(t_v2D v1, const double scalar);
t_v2D	divide_vector(t_v2D v1, const double scalar);
t_v2D	normalize_vector(t_v2D v1);
t_v2D	perp_vector(t_v2D v1);
double	length_vector(t_v2D v1);

#endif