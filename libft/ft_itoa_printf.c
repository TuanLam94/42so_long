/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:44:30 by tlam              #+#    #+#             */
/*   Updated: 2023/12/04 12:12:13 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	allocate(size_t len, size_t i, int n, char *dest)
{
	dest[len] = '\0';
	while (len-- > i)
	{
		if (n < 0)
		{
			dest[len] = (n % 10) * (-1) + '0';
			n /= 10;
		}
		else
		{
			dest[len] = '0' + n % 10;
			n /= 10;
		}
	}
}

char	*ft_itoa_printf(int n)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = ft_nbrlen(n);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (n < 0)
	{
		dest[0] = '-';
		i = 1;
	}
	else
		i = 0;
	allocate(len, i, n, dest);
	return (dest);
}

static int	ft_unbrlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa_printf(unsigned int n)
{
	char	*dest;
	size_t	len;

	len = ft_unbrlen(n);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (n)
	{
	dest[len - 1] = '0' + n % 10;
	n /= 10;
	len--;
	}
	return (dest);
}
