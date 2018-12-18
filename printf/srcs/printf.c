/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:32:04 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/18 11:21:11 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../printf.h"
#include "../libft/includes/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 'd' || *format == 'i')
				int_converter(va_arg(ap, int), *format);
			else if (*format == 'p')
				convert_to_hexa(va_arg(ap, void *));
		}
		format++;
	}
	return (0);
}


