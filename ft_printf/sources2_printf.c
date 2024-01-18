/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:14:36 by tlam              #+#    #+#             */
/*   Updated: 2023/11/20 17:16:57 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_x(unsigned int nb, int type)
{
	char	*hex;
	int		len;

	len = ft_putnbr_count_hex(nb);
	if (type == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb >= 16)
		ft_putnbr_hex_x(nb / 16, type);
	ft_putchar(hex[nb % 16]);
	return (len);
}

static void	write_ptr(unsigned long long nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		write_ptr(nb / 16);
	ft_putchar(hex[nb % 16]);
}

int	ft_putnbr_hex_ptr(unsigned long long nb)
{
	int	len;

	len = ft_putnbr_count_hex(nb);
	if (nb == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	len += ft_putstr("0x");
	write_ptr(nb);
	return (len);
}

int	ft_putnbr_count(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_count_hex(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}
