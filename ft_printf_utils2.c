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

static char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		len;
	unsigned int	number;
	int				sign;

	sign = 1;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}

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
