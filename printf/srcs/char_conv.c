/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:41:14 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/18 15:42:14 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/includes/libft.h"
#include "../printf.h"
#include <stdio.h>

char	*ft_printf_itoa_base(uintmax_t nb, int base)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 1;
	while (ft_power(base, i) - 1 < nb)
		i++;
	ret = ft_strnew(i);
	while (i-- > 0)
	{
		ret[i] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb /= base;
	}
	if (*ret == '0' && ret[1])
	{
		tmp = ret;
		while (*ret == '0')
			ret++;
		ret = ft_strdup(ret);
		free(tmp);
	}
	return (ret);
}
