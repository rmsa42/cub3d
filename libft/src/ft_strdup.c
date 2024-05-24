/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:45:39 by rumachad          #+#    #+#             */
/*   Updated: 2024/05/23 11:01:58 by jmarinho         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char			*duplicate;
	unsigned int	i;
	unsigned int	strlen;

	if (s == NULL)
		return (NULL);
	duplicate = NULL;
	i = 0;
	strlen = ft_strlen(s);
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
}

/* int main()
{
	char str[] = "Hello";
	char *a;

	a = ft_strdup(&str[0]);
	printf("%s\n", a);
	free(a);
} */