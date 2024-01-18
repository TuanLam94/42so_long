/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:35:07 by tlam              #+#    #+#             */
/*   Updated: 2023/11/20 18:35:08 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FT_PRINTF_H
# define    FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		def_type(va_list args, const char *format, int i);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putnbr_hex_x(unsigned int nb, int type);
int		ft_putnbr_hex_ptr(unsigned long long nb);
int		ft_putnbr_count(int nb);
int		ft_putnbr_count_hex(unsigned long long nb);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);

#endif
