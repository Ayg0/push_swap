/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:58:35 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/12/01 14:25:08 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_up(char *s, int a, int flag)
{
	int				i;
	unsigned int	b;

	i = 0;
	if (!flag)
		return (write(1, &a, 1));
	else if (flag == 1)
	{
		if (!s)
			return (write(1, "(null)", 6));
		while (s[i])
		{
			i += write(1, &s[i], 1);
		}
		return (i);
	}
	b = (unsigned int)a;
	ft_putnbr_base(b, 10, "0123456789");
	while (b || i == 0)
	{
		b /= 10;
		i++;
	}
	return (i);
}

int	printnum(int c)
{
	long	i;

	i = c;
	if (i < 0)
	{
		i *= -1;
		c = write(1, "-", 1);
	}
	else
		c = 0;
	ft_putnbr_base(i, 10, "0123456789");
	while (i || c == 0)
	{
		i /= 10;
		c++;
	}
	return (c);
}
