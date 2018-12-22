/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:07:37 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/22 21:03:59 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdint.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
void		int_converter(int arg, char format);
void		convert_to_hexa(void *arg);
char		*ft_printf_itoa_base(uintmax_t nb, int base, char c);
void		unsigned_int_converter(char other_flag, unsigned int arg, char format);
int			check_flag(const char *format);
intmax_t	signed_int_flag(int flag, va_list arg);
uintmax_t	unsigned_int_flag(int flag, va_list arg);
char		*ft_printf_dtoa(double nb);
char		*ft_create_flag_list(char *list, char other_flag);
void		ft_doublepourcent(const char *format);
char		*ft_flag_zero(int width);
int			ft_width(const char *format);
void		ft_put_flag(char *flag_list, char format, int width);

#endif
