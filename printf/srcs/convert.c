/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:09:16 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/18 20:12:27 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../printf.h"
#include <stdio.h>

/*uintmax_t	signed_int_flag(char flag, va_list arg)
{
	if (flag == 'h')
		return ((short int)va_arg(ap, int));
	else if (flag == 'l')
		return (va_arg(ap, long int));
	else if (flag == 'i')
		return ((char)va_arg(ap, int));
	else if (flag == 'j')
		return (va_arg(ap, long long int);
}

uintmax_t	unsigned_int_flag(char flag, va_list arg)
{
	if (flag == 'h')
		return ((unsigned short int)va_arg(ap, int));
	else if (flag == 'l')
		return (va_arg(ap, unsigned long int));
	else if (flag == 'i')
		return ((unsigned char)va_arg(ap, int));
	else if (flag == 'j')
		return (va_arg(ap, unsigned long long int);
}
*/
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
