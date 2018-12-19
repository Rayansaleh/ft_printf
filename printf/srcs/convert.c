/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:09:16 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/19 19:53:09 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../printf.h"
#include <stdio.h>

intmax_t	signed_int_flag(int flag, va_list arg)
{
	if (flag == 1)
		return ((short int)va_arg(arg, int));
	else if (flag == 2)
		return (va_arg(arg, long int));
	else if (flag == -1)
		return ((char)va_arg(arg, int));
	else if (flag == -2)
		return (va_arg(arg, long long int));
	return (va_arg(arg, int));
}

uintmax_t	unsigned_int_flag(int flag, va_list arg)
{
	if (flag == 1)
		return ((unsigned short int)va_arg(arg, int));
	else if (flag == 2)
		return (va_arg(arg, unsigned long int));
	else if (flag == -1)
		return ((unsigned char)va_arg(arg, int));
	else if (flag == -2)
		return (va_arg(arg, unsigned long long int));
	return (va_arg(arg, unsigned int));
}

void	int_converter(int arg, char format)
{
	if (format == 'c')
		ft_putchar(arg);
	else if (format == 'd' || format == 'i')
		ft_putnbr(arg);
}

void	convert_to_hexa(void *arg)
{
	char	*hexa;

	hexa = NULL;
	hexa = ft_printf_itoa_base((uintmax_t)arg, 16, 'a');
	ft_putstr("0x");
	ft_putstr(hexa);
}

void	unsigned_int_converter(unsigned int arg, char format)
{
	char *ret;

	ret = NULL;
	if (format == 'o')
		ret = ft_printf_itoa_base(arg, 8, 'a');
	else if (format == 'u')
		ret = ft_printf_itoa_base(arg, 10, 'a');
	else if (format == 'x')
		ret = ft_printf_itoa_base(arg, 16, 'a');
	else if (format == 'X')
		ret = ft_printf_itoa_base(arg, 16, 'A');
	ft_putstr(ret);
}
