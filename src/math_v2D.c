/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_v2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:15:01 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/18 13:53:23 by rumachad         ###   ########.fr       */
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

	v3.x = v1.x / v2.x;
	v3.y = v1.y / v2.y;

	return (v3);
}
