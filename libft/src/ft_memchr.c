/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:57:49 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*cs;

	cs = (char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (char)c)
			return (&cs[i]);
		i++;
	}
	return (NULL);
}

/* int main()
{
	char s[] = "";
	printf("%p\n", ft_memchr(&s[0], 'y', 5));
} */