/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_v2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:40:42 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/19 17:44:45 by rumachad         ###   ########.fr       */
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
	return (divide_vector(v1, create_vector(length, length)));
}

t_v2D	perp_vector(t_v2D v1)
{
	t_v2D	perp;

	perp.x = v1.y;
	perp.y = -v1.x;

	return (perp);	
}

void	print_vector(t_v2D vector)
{
	printf("Vector x: %f\n", vector.x);
	printf("Vector y: %f\n", vector.y);
}
