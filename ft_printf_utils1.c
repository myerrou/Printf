/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:50:34 by myerrou           #+#    #+#             */
/*   Updated: 2023/12/03 20:59:15 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(int num)
{
	char	*numb;
	int		len;

	len = 0;
	numb = (char *)ft_itoa(num);
	len += ft_putstr(numb);
	free(numb);
	return (len);
}

int	ft_print_p(unsigned long pass)
{
	int	ret;

	ret = 0;
	if (pass > 15)
	{
		ret += ft_print_p(pass / 16);
		ret += ft_print_p(pass % 16);
	}
	else
		ret += ft_putchar("0123456789abcdef"[pass]);
	return (ret);
}
