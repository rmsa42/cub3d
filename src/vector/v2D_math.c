/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2D_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:15:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/06 22:46:17 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2D.h"

t_v2D	add_vector(t_v2D v1, t_v2D v2)
{
	t_v2D	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	return (v3);
}

t_v2D	minus_vector(t_v2D v1, t_v2D v2)
{
	t_v2D	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	return (v3);
}

t_v2D	multiply_vector(t_v2D v1, const double scalar)
{
	t_v2D	v2;

	v2.x = v1.x * scalar;
	v2.y = v1.y * scalar;
	return (v2);
}

t_v2D	divide_vector(t_v2D v1, const double scalar)
{
	t_v2D	v2;

	v2 = create_vector(0, 0);
	if (scalar == 0)
		return (v2);
	v2.x = v1.x / scalar;
	v2.y = v1.y / scalar;
	return (v2);
}

double	length_vector(t_v2D v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y));
}
