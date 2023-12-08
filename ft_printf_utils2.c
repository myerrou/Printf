/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:24:24 by myerrou           #+#    #+#             */
/*   Updated: 2023/12/03 14:57:11 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int pass)
{
	int	ret;

	ret = 0;
	if (pass > 15)
	{
		ret += ft_print_hex(pass / 16);
		ret += ft_print_hex(pass % 16);
	}
	else
		ret += ft_putchar("0123456789abcdef"[pass]);
	return (ret);
}

int	ft_print_uhex(unsigned int pass)
{
	int	ret;

	ret = 0;
	if (pass > 15)
	{
		ret += ft_print_uhex(pass / 16);
		ret += ft_print_uhex(pass % 16);
	}
	else
		ret += ft_putchar("0123456789ABCDEF"[pass]);
	return (ret);
}

char	*ft_conv(unsigned long num, char *set)
{
	static char	buff[10];
	char		*ptr;

	ptr = &buff[9];
	*ptr = '\0';
	*--ptr = set[num % 10];
	num /= 10;
	while (num != 0)
	{
		*--ptr = set[num % 10];
		num /= 10;
	}
	return (ptr);
}

int	ft_printf_scanner(char type, va_list macro)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_putchar(va_arg(macro, int));
	else if (type == 's')
		count = ft_putstr(va_arg(macro, char *));
	else if (type == 'p')
	{
		count = ft_putstr("0x");
		count += ft_print_p(va_arg(macro, unsigned long));
	}
	else if (type == 'd' || type == 'i')
		count = ft_putnbr(va_arg(macro, int));
	else if (type == 'u')
		count = ft_putstr(ft_conv(va_arg(macro, unsigned int), "0123456789"));
	else if (type == 'x')
		count = ft_print_hex(va_arg(macro, unsigned int));
	else if (type == 'X')
		count = ft_print_uhex(va_arg(macro, unsigned int));
	else if (type == '%')
		count = ft_putchar('%');
	else
		count = ft_putchar(type);
	return (count);
}
