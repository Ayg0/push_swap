/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_makers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:16:52 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 23:13:59 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(int ac, char **av, t_all	*all, int flag)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = num_of_slots(ac, av);
	all->a = ft_calloc(i + 1, sizeof(int));
	all->b = ft_calloc(i + 1, sizeof(int));
	all->a[0] = i;
	i = 1;
	j = 1;
	while (i < ac)
	{
		k = 0;
		arr = ft_split(av[i], ' ');
		while (arr[k])
		{
			all->a[j++] = ft_atoi(arr[k]);
			k++;
		}
		why_r_ya_running(arr, k);
		i++;
	}
	if (flag && is_it_sorted(all->a))
		exit(0);
	all->sorted = NULL;
	make_sorted(all);
}

int	*make_temp(t_all *all)
{
	int	i;
	int	*temp;

	temp = ft_calloc(all->a[0] + 1, sizeof(int));
	i = -1;
	while (++i <= all->a[0])
		temp[i] = all->a[i];
	return (temp);
}

int	direct(t_all *all, int j)
{
	int	i;
	int	*temp;

	i = 0;
	temp = make_temp(all);
	while (temp[1] != all->sorted[1] && (temp[1] != all->sorted[2] || j))
	{
		rotate(temp, NULL);
		i++;
	}
	free(temp);
	return (i < (all->a[0] / 2) - 1);
}

void	make_sorted(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	if (all->sorted)
		free(all->sorted);
	all->sorted = (int *)ft_calloc(all->a[0] + 1, sizeof(int));
	while (i < all->a[0] + 1)
	{
		all->sorted[i] = all->a[i];
		j = 1;
		while (j < i)
		{
			if (all->sorted[i] == all->sorted[j])
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	sort_it(all);
}
