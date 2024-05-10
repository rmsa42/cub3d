/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2D_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:40:42 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/26 17:14:38 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2D.h"

t_v2D	create_vector(double x, double y)
{
	t_v2D	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_v2D	normalize_vector(t_v2D v1)
{
	double	length;

	length = length_vector(v1);
	return (divide_vector(v1, length));
}

t_v2D	perp_vector(t_v2D v1)
{
	t_v2D	perp;

	perp.x = -v1.y;
	perp.y = v1.x;
	return (perp);
}

void	print_vector(t_v2D vector)
{
	printf("Vector: %f %f\n", vector.x, vector.y);
}
