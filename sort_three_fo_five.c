/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_fo_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:05:31 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 11:46:21 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_thee(t_all *all)
{
	int	i;

	i = all->a[0] - 3;
	while (i)
	{
		if (all->a[1] == all->sorted[1] || all->a[1] == all->sorted[2])
		{
			push(all->a, all->b, "pb\n");
			if (!(--i))
				break ;
		}
		if (direct(all, 0))
			rotate(all->a, "ra\n");
		else
			reverse_rotate(all->a, "rra\n");
	}
	if (is_it_sorted(all->b))
		swap(all->b, "sb\n");
	if (!is_it_sorted(all->a))
	{
		make_sorted(all);
		sort_t(all);
	}
	push(all->b, all->a, "pa\n");
	push(all->b, all->a, "pa\n");
}

void	sort_f(t_all *all)
{
	if (all->a[0] == 4)
		return (sort_ff(all));
	sort_thee(all);
}

void	sort_ff(t_all *all)
{
	while (all->a[1] != all->sorted[1])
		rotate(all->a, "ra\n");
	if (is_it_sorted(all->a))
		exit(0);
	push(all->a, all->b, "pb\n");
	if (!is_it_sorted(all->a))
	{
		make_sorted(all);
		sort_t(all);
	}
	push(all->b, all->a, "pa\n");
}

int	is_it_sorted(int *a)
{
	int	i;

	i = 1;
	while (i < a[0])
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_t(t_all *all)
{
	int	i[2];

	if (all->a[0] == 2)
		exit(swap(all->a, "sa\n"));
	which_which(all, &i[0], &i[1]);
	if (i[0] == 1 && i[1] == 2)
	{
		reverse_rotate(all->a, "rra\n");
		swap(all->a, "sa\n");
	}
	else if (i[0] == 2 && i[1] == 3)
		swap(all->a, "sa\n");
	else if (i[0] == 3 && i[1] == 1)
	{
		rotate(all->a, "ra\n");
		swap(all->a, "sa\n");
	}
	else if (i[0] == 2 && i[1] == 1)
		rotate(all->a, "ra\n");
	else
		reverse_rotate(all->a, "rra\n");
}
