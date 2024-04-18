/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:36:50 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:53:38 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "../libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (2);
	}
	else if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* int	main()
{
	int a = '0';
	printf("%d\n", ft_isalpha(a));
} */