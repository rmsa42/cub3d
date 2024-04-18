/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_upp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:36:57 by rui               #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
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

int	ft_printhexa_upp(unsigned int nbr)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(*(hexa + nbr));
	else
	{
		ft_printhexa_upp(nbr / 16);
		ft_printhexa_upp(nbr % 16);
	}
	return (len(nbr));
}
