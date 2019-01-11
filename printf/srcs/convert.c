/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:29:06 by rsaleh            #+#    #+#             */
/*   Updated: 2019/01/11 21:44:30 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/includes/libft.h"
#include "../printf.h"
#include <stdio.h>

void	ft_printf_flag_fill(uintmax_t tmp, int base, char *str, t_printf *pf)
{
	int size;

	if (!(pf->ff & ISADDRESS) && (pf->ff & ZERO) && (pf->ff & DIEZ)
			&& base == 16 && !(pf->ff & LONGLONG) && pf->finalsize > 3)
		pf->finalsize -= 2;
	size = pf->finalsize;
	pf->arg = (pf->arg == 'X') ? 'A' - 10 : 'a' - 10;
	while (size--)
	{
		str[size] = tmp % base + ((tmp % base < 10) ? '0' : pf->arg);
		tmp /= base;
	}
}

void	ft_printf_itoa_base(uintmax_t nb, t_printf *pf, int base)
{
	uintmax_t 	tmp;
	char		str[21];
	int			vsize;
	int			diff;

	tmp = nb;
	while (tmp)
	{
		tmp /= base;
		++pf->finalsize;
	}
	pf->precision = ((pf->ff & ZERO) && !(pf->ff & ISADDRESS)) ?
		pf->width : pf->precision;
	vsize = (pf->finalsize >= pf->precision) ? 0 : 1;
	pf->finalsize = (pf->finalsize & (pf->precision - pf->finalsize) >> 31) |
		(pf->precision & (~(pf->precision - pf->finalsize) >> 31));
	((pf->ff & DIEZ) && base == 8 && !vsize) ? --pf->width : 0;
	((pf->ff & DIEZ) && base == 16 && !(pf->ff & ZERO)) ? pf->width -= 2 : 0;
	diff = pf->width - pf->finalsize;
	pf->width = (diff & (0 - diff) >> 31) |
		(0 & (~(0 - diff) >> 31));
	put_width(pf, 0);
	if (((nb || (pf->ff & ISADDRESS)) && (pf->ff & DIEZ) &&
				((base == 8 && !vsize) || base == 16)))
		create_buffer("0", 1, pf);
	if ((nb || (pf->ff & ISADDRESS)) && (pf->ff & DIEZ) && base == 16)
		create_buffer((pf->arg == 'X') ? "X" : "x", 1, pf);
	ft_printf_flag_fill(nb, base, str, pf);
	create_buffer(str, pf->finalsize, pf); 
	put_width(pf, 1);
}

void	ft_printf_itoa(intmax_t nb, t_printf *pf)
{
	uintmax_t	tmp;
	char		str[21];
	int			len;

	len = 0;
	tmp = (nb < 0) ? -nb : nb;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if ((pf->ff & PLUS || (pf->ff & SPACE && pf->ff & ZERO) || nb < 0))
		--pf->precision;
	pf->finalsize = (pf->precision & ((len - pf->precision) >> 31)) |
		(len & (~(len - pf->precision) >> 31));
	if (pf->ff & PLUS || pf->ff & SPACE || nb < 0)
		++pf->finalsize;
	pf->width = (pf->finalsize > pf->width) ? 0 : pf->width - pf->finalsize;
	put_width(pf, 0);
	tmp = (nb < 0) ? -nb : nb;
	ft_printf_flag_fill(tmp, 10, str, pf);
	(pf->ff & SPACE) ? str[0] = ' ' : 0;
	(nb < 0) ? str[0] = '-' : 0;
	(pf->ff & PLUS && nb >= 0) ? str[0] = '+' : 0;
	create_buffer(str, pf->finalsize, pf);
	put_width(pf, 1);
}

void	printf_putfloat(t_printf *pf)
{
	double 	n;
	int		size;

	nb = va_arg(pf->ap, double);
	!(pf->ff & ISPRECI) ? pf->precision = 6 : 0;
	tmp = (nb > 0) ? nb : -nb;
	while (tmp)
	{
		tmp /= 10;
		size++;
	}
	(pf->ff & ZERO) ? pf->precision = pf->width : 0;
		

}
