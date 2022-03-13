/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:17:43 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/12/01 14:17:14 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long a, unsigned long len, char *s)
{
	if (a >= len)
		ft_putnbr_base((a / len), len, s);
	write(1, &s[a % len], 1);
}

int	print_hex(unsigned long p, int pointer, int big)
{
	int	i;

	i = 0;
	if (pointer)
	{
		i += write(1, "0x", 2);
		if (!p)
			i++;
	}
	if (big)
		ft_putnbr_base(p, 16, "0123456789ABCDEF");
	else
		ft_putnbr_base(p, 16, "0123456789abcdef");
	while (p || i == 0)
	{
		p /= 16;
		i++;
	}
	return (i);
}

int	check_and_print(char s, va_list p)
{
	int	i;

	i = 0;
	if (s == 'c')
		i += flag_up(NULL, va_arg(p, int), 0);
	else if (s == 's')
		i += flag_up(va_arg(p, char *), 0, 1);
	else if (s == 'p')
		i += print_hex(va_arg(p, unsigned long), 1, 0);
	else if (s == 'd' || s == 'i')
		i += printnum(va_arg(p, int));
	else if (s == 'u')
		i += flag_up(NULL, va_arg(p, unsigned int), 3);
	else if (s == 'x')
		i += print_hex(va_arg(p, unsigned int), 0, 0);
	else if (s == 'X')
		i += print_hex(va_arg(p, unsigned int), 0, 1);
	else
		i += write(1, &s, 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		i;
	int		k;

	i = 0;
	k = 0;
	va_start(p, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			k += check_and_print(s[i], p);
		}
		else
			k += write(1, &s[i], 1);
		i++;
	}
	va_end(p);
	return (k);
}
