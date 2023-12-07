/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:18:45 by myerrou           #+#    #+#             */
/*   Updated: 2023/12/06 17:27:45 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_conv(unsigned long num, char *set)
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

static int	ft_printf_scanner(char type, va_list macro)
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

int	ft_printf(const char *format, ...)
{
	va_list	macro;
	int		i;
	int		len;

	va_start(macro, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			len += ft_printf_scanner(format[i + 1], macro);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(macro);
	return (len);
}
