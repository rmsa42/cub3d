/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_v2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:40:42 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/18 13:51:25 by rumachad         ###   ########.fr       */
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

void	print_vector(t_v2D vector)
{
	printf("Vector x: %f\n", vector.x);
	printf("Vector y: %f\n", vector.y);
}
