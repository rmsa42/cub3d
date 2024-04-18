/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:29:49 by rumachad          #+#    #+#             */
/*   Updated: 2023/12/27 10:09:40 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_fputstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (*s != '\0')
	{
		ft_fputchar(*s++, fd);
		i++;
	}
	return (i);
}
