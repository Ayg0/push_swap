/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:33:45 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 23:20:17 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;
	int		i;

	i = count * size;
	b = malloc(i);
	if (b == NULL)
		exit (write(2, "Error, allocation Error.\n", 26));
	while (i)
		((char *)b)[--i] = 0;
	return (b);
}

int	num_of_slots(int ac, char **av)
{
	int		i[2];
	char	**arr;

	i[1] = 0;
	if (ac == 1)
		exit(0);
	while (ac > 1)
	{
		arr = ft_split(av[ac - 1], ' ');
		i[0] = 0;
		while (arr[i[0]])
			i[0]++;
		i[1] += i[0];
		why_r_ya_running(arr, i[0]);
		ac--;
	}
	return (i[1]);
}

void	sort_it(t_all *all)
{
	int	i;
	int	j;

	i = 1;
	while (i < all->sorted[0])
	{
		j = 1;
		while (j < all->sorted[0] - i + 1)
		{
			if (all->sorted[j] > all->sorted[j + 1])
			{
				all->sorted[j] ^= all->sorted[j + 1];
				all->sorted[j + 1] ^= all->sorted[j];
				all->sorted[j] ^= all->sorted[j + 1];
			}
			j++;
		}
		i++;
	}
}
