/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:31:59 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:53:54 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <stdlib.h>
#include "../libft.h"

static int	len(int num)
{
	int	i;

	i = 0;
	if (num < 0 || num == 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*loop(char *str, int nlen, long long num)
{
	while (num != 0)
	{
		str[nlen--] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			nlen;
	long long	num;
	char		*str;

	num = (long long)n;
	nlen = len(num);
	str = (char *)malloc((nlen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	str[nlen--] = '\0';
	if (num == 0)
		str[0] = '0';
	loop(str, nlen, num);
	return (str);
}

/* int main()
{
	char *a;
	a = ft_itoa(130);
	printf("%s\n", a);
	free(a); 
} */