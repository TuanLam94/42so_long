/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:26:15 by tlam              #+#    #+#             */
/*   Updated: 2023/11/20 17:08:08 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	def_type(va_list args, const char *format, int i)
{
	int	len;

	len = 0;
	if (format[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		len += ft_putnbr_hex_ptr(va_arg(args, unsigned long long));
	else if (format[i] == 'd' || format[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		len += ft_putnbr_hex_x(va_arg(args, unsigned int), 1);
	else if (format[i] == 'X')
		len += ft_putnbr_hex_x(va_arg(args, unsigned int), 2);
	else if (format[i] == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += def_type(args, format, i + 1);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
