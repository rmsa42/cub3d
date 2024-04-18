/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:49:11 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "../libft.h"

void	*ft_memset(void *str, int c, size_t n)
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
}

/* int main()
{
	char str[] = "Hello";
	printf("%p\n", ft_memset(&str[0], '7', 2));
} */