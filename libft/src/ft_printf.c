/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:37:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	formats(const char format, va_list args, int nw)
{
	if (format == 'c')
		nw = ft_putchar(va_arg(args, int));
	else if (format == 's')
		nw = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		nw = ft_printpointer_start(va_arg(args, unsigned long));
	else if (format == 'd')
		nw = ft_putnbr(va_arg(args, int));
	else if (format == 'i')
		nw = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		nw = ft_put_unsi_nbr(va_arg(args, unsigned int));
	else if (format == 'x')
		nw = ft_printhexa(va_arg(args, unsigned int));
	else if (format == 'X')
		nw = ft_printhexa_upp(va_arg(args, unsigned int));
	else if (format == '%')
		nw = ft_putchar('%');
	return (nw);
}

int	ft_printf(const	char *format, ...)
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
			k = formats(format[i], args, k);
			nw = k + nw;
		}
		else
		{
			nw++;
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (nw);
}
