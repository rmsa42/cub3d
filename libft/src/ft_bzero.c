/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:29:32 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:53:26 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "../libft.h"

void	ft_bzero(void *str, size_t size)
{
	size_t			i;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *)str;
	while (i < size)
	{
		str2[i] = '\0';
		i++;
	}
}

/* int	main()
{
	char name[] = "Hello";
	char *a;
	int n = 3;
	int i = 0;
	
	a = ft_bzero(&name[0], n);
	while (i < 5)
	{
		printf("%c", a[i]);
		i++;
	}
	printf("\n");
} */