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
