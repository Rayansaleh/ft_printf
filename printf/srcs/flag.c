/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:20:01 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/22 21:04:08 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/includes/libft.h"

void	ft_doublepourcent(const char *format)
{
	if (*format == '%')
		ft_putchar('%');
}

void	ft_flag_zero(int width)
{
	while (width--)
		ft_putchar('0');
}
