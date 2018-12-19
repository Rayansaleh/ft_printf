/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:32:04 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/19 21:02:42 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"
#include "../libft/includes/libft.h"

int		check_flag(const char *format)
{
	if (*format == 'h')
	{
		format++;
		if (*format == 'h')
			return (-1);
		else
			return (1);
	}
	else if (*format == 'l')
	{
		format++;
		if (*format == 'l')
			return (-2);
		else
			return (2);
	}
	return (0);
}

void	check_arg(int flag, va_list arg, char format)
{
	if (format == 'c' || format == 'd' || format == 'i')
		int_converter(signed_int_flag(flag, arg), format);
	else if (format == 's')
		ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		convert_to_hexa(va_arg(arg, void *));
	else if (format == 'o' || format == 'u' ||
			format == 'x' || format == 'X')
		unsigned_int_converter(unsigned_int_flag(flag, arg), format);
	else if (format == 'f')
		ft_printfloat(va_arg(arg, double), 5);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		flag;
	
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format += ((flag = check_flag(format)) > 0) ? 1 : 2;
			format -= (flag == 0) ? 2 : 0;
			check_arg(flag, ap, *format);
		}
		format++;
	}
	return (0);
}
