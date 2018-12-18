/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:07:37 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/18 17:14:54 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	int_converter(int arg, char format);
void	convert_to_hexa(void *arg);
char	*ft_printf_itoa_base(uintmax_t nb, int base, char c);
void	unsigned_int_converter(unsigned int arg, char format);

#endif
