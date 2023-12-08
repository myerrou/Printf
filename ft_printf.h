/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:39:18 by myerrou           #+#    #+#             */
/*   Updated: 2023/12/08 15:24:46 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_strlen(char *str);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_print_p(unsigned long pass);
int		ft_print_hex(unsigned int pass);
int		ft_print_uhex(unsigned int pass);
int		ft_printf_scanner(char type, va_list macro);
char	*ft_conv(unsigned long num, char *set);

#endif
