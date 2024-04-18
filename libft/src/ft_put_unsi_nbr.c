/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsi_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:16:06 by rumachad          #+#    #+#             */
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
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_put_unsi_nbr(unsigned int n)
{
	int		k;
	char	c;

	k = len(n);
	if (n < 10)
	{
		c = n + '0';
		ft_putchar(c);
	}
	else
	{
		ft_put_unsi_nbr(n / 10);
		ft_put_unsi_nbr(n % 10);
	}
	return (k);
}
