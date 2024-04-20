/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_v2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:15:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/20 01:02:14 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2D.h"

t_v2D add_vector(t_v2D v1, t_v2D v2)
{
	t_v2D	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	
	return (v3);
}

t_v2D minus_vector(t_v2D v1, t_v2D v2)
{
	t_v2D	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;

	return (v3);
}

t_v2D multiply_vector(t_v2D v1, t_v2D v2)
{
	t_v2D	v3;

	v3.x = v1.x * v2.x;
	v3.y = v1.y * v2.y;
	
	return (v3);
}

t_v2D divide_vector(t_v2D v1, t_v2D v2)
{
	t_v2D	v3;

	v3 = create_vector(0, 0);
	if (v2.x != 0)
		v3.x = v1.x / v2.x;
	if (v2.y != 0)
		v3.y = v1.y / v2.y;

	return (v3);
}

double	length_vector(t_v2D v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y));	
}
