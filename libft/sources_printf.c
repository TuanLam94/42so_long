/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:52:45 by tlam              #+#    #+#             */
/*   Updated: 2023/11/20 16:37:34 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int		len;
	char	*num;

	num = ft_itoa(nb);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int		len;
	char	*num;

	len = 0;
	if (nb == 0)
	{
		len++;
		write(1, "0", 1);
	}
	else
	{
		num = ft_uitoa(nb);
		len = ft_putstr(num);
		free(num);
	}
	return (len);
}
