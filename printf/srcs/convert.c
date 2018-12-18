/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:09:16 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/18 15:33:48 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../printf.h"
#include <stdio.h>

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
	hexa = ft_printf_itoa_base((uintmax_t)arg, 16);
	ft_putstr("0x");
	ft_putstr(hexa);
}

/*void	unsigned_int_converter(unsigned int arg, char format)
{
	unsigned int	octal;
	int				i;

	i = 1;
	octal = 0;
	while (arg)
	{
		octal += (arg % 8) * i;
		arg /= 8;
		i *= 10;
	}
}*/
