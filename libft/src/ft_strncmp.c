/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:15:14 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(char *str1, char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while ((str1[i] == str2[i]) && (i < size - 1) && str1[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)(str1[i]) - (unsigned char)(str2[i]));
}

/* int main()
{
	char str1[] = "abcdef";
	char str2[] = "ab\375xx";

	printf("%d\n", ft_strncmp(&str1[0], &str2[0], 5));
} */