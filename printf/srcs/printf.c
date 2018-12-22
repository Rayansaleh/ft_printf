/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:32:04 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/22 21:04:04 by rsaleh           ###   ########.fr       */
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

char	check_other_flag(const char *format)
{
	if (*format == '#')
		return ('#');
	if (*format == '0')
		return ('0');
	if (*format == '-')
		return ('-');
	if (*format == '+')
		return ('+');
	return (0);
}


void	check_arg(char other_flag, int flag, va_list arg, char format)
{
	if (format == 'c' || format == 'd' || format == 'i')
		int_converter(signed_int_flag(flag, arg), format);
	else if (format == 's')
		ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		convert_to_hexa(va_arg(arg, void *));
	else if (format == 'o' || format == 'u' ||
			format == 'x' || format == 'X')
		unsigned_int_converter(other_flag, unsigned_int_flag(flag, arg), format);
	else if (format == 'f')
		ft_printfloat(va_arg(arg, double), 5);
}

void	ft_put_flag(char *flag_list, char format, int width)
{
	while (*flag_list)
	{
		if (*flag_list == '#')
		{
			if (format == 'o')
					ft_putchar('0');
			else if (format == 'x')
				ft_putstr("0x");
			else if (format == 'X')
				ft_putstr("0X");
		}
		else if(*flag_list == '0' && !(ft_strchr(flag_list, '-')))
			ft_flag_zero(width);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		flag;
	char	*flag_list;
	char	other_flag;
	int		width;

	va_start(ap, format);
	if (!(flag_list = (char*)malloc(sizeof(char) * 6)))
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_doublepourcent(format);
			while ((other_flag = check_other_flag(format)) != 0)
			{
				flag_list = ft_create_flag_list(flag_list, other_flag);
				format++;
			}
			width = ft_width(format);
			format += (ft_count(width) == 0) ? ft_count(width) : 0;
			//while (width--)
			//	ft_putchar(' ');
			format += ((flag = check_flag(format)) > 0) ? 1 : 2;
			format -= (flag == 0) ? 2 : 0;
			ft_put_flag(flag_list, *format, width);
			check_arg(other_flag, flag, ap, *format);
		}
		format++;
	}
	return (0);
}
