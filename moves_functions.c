/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:14:39 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 11:46:49 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int *a, char *s)
{
	if (a[0] > 1)
	{
		a[1] ^= a[2];
		a[2] ^= a[1];
		a[1] ^= a[2];
	}
	if (s)
		write(1, s, ft_strlen(s));
	return (1);
}

int	reverse_rotate(int *a, char *s)
{
	int	k;
	int	i;

	k = a[a[0]];
	i = a[0];
	while (i >= 1)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[1] = k;
	if (s)
		write(1, s, ft_strlen(s));
	return (1);
}

int	rotate(int *a, char *s)
{
	int	k;
	int	i;

	k = a[1];
	i = 1;
	while (i < a[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = k;
	if (s)
		write(1, s, ft_strlen(s));
	return (1);
}

int	push(int *from, int *to, char *s)
{
	int	i;

	if (!(from[0] > 0))
		return (1);
	i = to[0] + 1;
	while (i > 1)
	{
		to[i] = to[i - 1];
		i--;
	}
	to[1] = from[1];
	i = 1;
	while (i < from[0])
	{
		from[i] = from[i + 1];
		i++;
	}
	from[0]--;
	if (s)
		write(1, s, ft_strlen(s));
	to[0]++;
	return (1);
}
