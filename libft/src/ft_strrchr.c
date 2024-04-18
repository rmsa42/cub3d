/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:43:32 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "../libft.h"

/* size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
} */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	character;
	char	*str2;

	i = ft_strlen(str);
	str2 = (char *)str;
	character = (char)c;
	while (i >= 0)
	{
		if (str2[i] == character)
		{
			return (&str2[i]);
		}
		i--;
	}
	return (NULL);
}

/* int main()
{
	char mstr[] = "aaabcabcd";
	char sstr[] = "aabc";

	printf("%s\n", ft_strnstr(&mstr[0], &sstr[0], -1));
} */
