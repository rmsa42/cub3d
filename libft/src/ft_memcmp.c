/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:33:14 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] > str2[i])
		{
			return (str1[i] - str2[i]);
		}
		if (str1[i] < str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/* int main()
{
	char str1[] = "abc";
	char str2[] = "abc";

	printf("%d\n", ft_memcmp(&str1[0], &str2[0], 7));
} */