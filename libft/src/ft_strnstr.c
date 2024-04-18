/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:39:18 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
} */

char	*ft_strnstr(const char *mainstr, const char *substr, size_t len)
{
	unsigned int	i;
	unsigned int	k;
	char			*mainstr2;
	char			*substr2;

	i = 0;
	mainstr2 = (char *)mainstr;
	substr2 = (char *)substr;
	if (ft_strlen(substr) == 0)
		return (mainstr2);
	while ((i < len) && mainstr2[i] != '\0')
	{
		k = 0;
		while ((mainstr2[i + k] == substr2[k]) && (i + k) < len)
		{
			if (substr2[k + 1] == '\0')
				return (&mainstr2[i]);
			k++;
		}
		i++;
	}
	return (NULL);
}

/* int main()
{
	char mstr[] = "aaabcabcd";
	char sstr[] = "aabc";

	printf("%s\n", ft_strnstr(&mstr[0], &sstr[0], -1));
} */