/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprinthexa_upp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:36:57 by rui               #+#    #+#             */
/*   Updated: 2023/12/27 10:08:24 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	len(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int	ft_fprinthexa_upp(unsigned int nbr, int fd)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (nbr < 16)
		ft_fputchar(*(hexa + nbr), fd);
	else
	{
		ft_fprinthexa_upp(nbr / 16, fd);
		ft_fprinthexa_upp(nbr % 16, fd);
	}
	return (len(nbr));
}
