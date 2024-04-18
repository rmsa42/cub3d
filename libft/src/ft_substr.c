/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:14:27 by rumachad          #+#    #+#             */
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

/* size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
} */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start > ft_strlen(s) || s[i] == '\0')
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = (char *)malloc((len + 1) * sizeof(const char));
	if (str == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int main()
{
	char mstr[] = "";
	char *a;
	a = ft_substr(&mstr[0], 1, 1);
	printf("%s\n", a);
	free(a);
} */