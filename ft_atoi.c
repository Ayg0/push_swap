/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:34:11 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/02/19 10:50:40 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ret(unsigned long num, int sign)
{
	if (sign == 1 && num > 9223372036854775807ul)
		return (-1);
	else if (sign == -1 && num > 9223372036854775808ul)
		return (0);
	return ((int)num * sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (ret(num, sign));
}
