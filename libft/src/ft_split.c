/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:38:26 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	numw(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (*str != '\0')
	{
		if (*str == c)
			k = 0;
		else if (k == 0 && *str != c)
		{
			i++;
			k = 1;
		}
		str++;
	}
	return (i);
}

static char	*nstr(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**fstr;

	if (!s)
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	fstr = (char **)malloc((numw(s, c) + 1) * sizeof(char *));
	if (fstr == NULL)
		return (NULL);
	k = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			fstr[k++] = nstr((char *)s, c);
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	fstr[k] = 0;
	return (fstr);
}

/* int main()
{
	char str[] = "Hello,Hey";
	char **a;
	int i;

	i = 0;
	a = ft_split(&str[0], ',');
	while (i < 2)
	{
		printf("%s\n", a[i]);
		free(a[i]);
		i++;
	}
	free(a);
} */