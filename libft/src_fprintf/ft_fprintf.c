/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:37:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/12/27 10:15:30 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	formats(const char format, va_list args, int nw, int fd)
{
	if (format == 'c')
		nw = ft_fputchar(va_arg(args, int), fd);
	else if (format == 's')
		nw = ft_fputstr(va_arg(args, char *), fd);
	else if (format == 'p')
		nw = ft_fprintpointer_start(va_arg(args, unsigned long), fd);
	else if (format == 'd')
		nw = ft_fputnbr(va_arg(args, int), fd);
	else if (format == 'i')
		nw = ft_fputnbr(va_arg(args, int), fd);
	else if (format == 'u')
		nw = ft_fput_unsi_nbr(va_arg(args, unsigned int), fd);
	else if (format == 'x')
		nw = ft_fprinthexa(va_arg(args, unsigned int), fd);
	else if (format == 'X')
		nw = ft_fprinthexa_upp(va_arg(args, unsigned int), fd);
	else if (format == '%')
		nw = ft_fputchar(fd, '%');
	return (nw);
}

int	ft_fprintf(int fd, const	char *format, ...)
{
	int		i;
	int		nw;
	int		k;
	va_list	args;

	i = 0;
	nw = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			k = formats(format[i], args, k, fd);
			nw = k + nw;
		}
		else
		{
			nw++;
			ft_fputchar(format[i], fd);
		}
		i++;
	}
	va_end(args);
	return (nw);
}
