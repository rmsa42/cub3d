/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:04:16 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	len(unsigned long num)
{
	int	i;

	i = 2;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int	ft_printpointer(unsigned long nbr)
{
	char				*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(*(hexa + nbr));
	else
	{
		ft_printpointer(nbr / 16);
		ft_printpointer(nbr % 16);
	}
	return (len(nbr));
}

int	ft_printpointer_start(unsigned long nbr)
{
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_printpointer(nbr));
}
