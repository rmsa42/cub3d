/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprinthexa_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:29:03 by rumachad          #+#    #+#             */
/*   Updated: 2023/12/27 10:07:56 by rumachad         ###   ########.fr       */
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

int	ft_fprinthexa(unsigned int nbr, int fd)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 16)
		ft_fputchar(*(hexa + nbr), fd);
	else
	{
		ft_fprinthexa(nbr / 16, fd);
		ft_fprinthexa(nbr % 16, fd);
	}
	return (len(nbr));
}
