/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:07:27 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:53:30 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <stdlib.h>
#include "../libft.h"

/* void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	char			*cstr;

	cstr = (char *)str;
	i = 0;
	while (i < n)
	{
		cstr[i] = c;
		i++;
	}
	return (cstr);
} */

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;

	a = (void *)malloc(nitems * size);
	if (a == NULL)
		return (NULL);
	if ((nitems * size) > 2147483647)
		return (NULL);
	ft_memset(a, 0, (nitems * size));
	return (a);
}

/* int main()
{
	void *a;

	a = ft_calloc(10, 1);
	printf("%p\n", a);
	free(a);
} */