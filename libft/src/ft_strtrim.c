/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:16:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* char	*ft_strdup(const char *s)
{
	char			*duplicate;
	unsigned int	i;
	unsigned int	strlen;

	strlen = ft_strlen(&s[0]);
	i = 0;
	duplicate = (char *) malloc((strlen + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (i < strlen)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
} */

static int	ft_char(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	while (str2[i] != '\0')
	{
		if (str2[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;
	char			*fstr;

	i = 0;
	if (s1[i] == '\0' || set[i] == '\0')
		return (ft_strdup(s1));
	while (ft_char(set, s1[i]) == 1 && s1[i] != '\0')
		i++;
	k = ft_strlen(s1);
	while (ft_char(set, s1[k - 1]) == 1 && (k > i))
		k--;
	fstr = (char *)malloc((k - i + 1) * sizeof(char));
	if (fstr == NULL)
		return (NULL);
	j = 0;
	while (i < k)
	{
		fstr[j] = s1[i];
		i++;
		j++;
	}
	fstr[j] = '\0';
	return (fstr);
}

/* int main()
{
	char s1[] = "abcd";
	char *set = "";
	char *a;

	a = ft_strtrim(&s1[0], &set[0]);
	printf("%s\n", a);
	free(a);
} */