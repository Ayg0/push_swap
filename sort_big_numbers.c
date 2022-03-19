/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:24:24 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 12:07:11 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	who_will_go(t_all *all, int *down)
{
	if (*down == 0 || all->b[1] > all->a[all->a[0]])
	{
		push(all->b, all->a, NULL);
		print_multi("pa");
		if (all->a[1] != all->sorted[all->sorted[0]])
		{
			rotate(all->a, NULL);
			print_multi("ra");
			(*down)++;
		}
	}
	else
	{
		rotate(all->b, NULL);
		print_multi("rb");
	}
}

int	play_with_values(t_all *all, int *start, int *end)
{
	*start = (*start - all->offset) * (*start - all->offset >= 1)
		+ 1 * (*start - all->offset < 1);
	*end = (*end + all->offset) * (*end + all->offset <= all->sorted[0])
		+ all->sorted[0] * (*end + all->offset > all->sorted[0]);
	return (1);
}

void	from_a_to_b(t_all *all, int start, int end)
{
	int	i;

	i = 1;
	while (all->a[0])
	{
		if (all->a[1] >= all->sorted[start] && all->a[1] <= all->sorted[end])
		{
			push(all->a, all->b, NULL);
			print_multi("pb");
			if (all->b[1] < all->sorted[all->middle] && all->b[0] > 1)
			{
				rotate(all->b, NULL);
				print_multi("rb");
			}
			i++;
		}
		else
		{
			rotate(all->a, NULL);
			print_multi("ra");
		}
		(i == end - start) && play_with_values(all, &start, &end);
	}
}

void	looking_for_the_number(int *k, int *down, t_all *all)
{
	if (k[1] >= all->b[0] / 2)
	{
		reverse_rotate(all->b, NULL);
		print_multi("rrb");
	}
	else
		who_will_go(all, down);
}

void	from_b_to_a(t_all *all)
{
	int	down;
	int	k[2];

	down = 0;
	while (all->b[0] || down)
	{
		k[1] = get_index(all->b, all->sorted[all->sorted[0]]);
		if (all->b[1] == all->sorted[all->sorted[0]])
		{
			push(all->b, all->a, NULL);
			print_multi("pa");
			all->sorted[0]--;
		}
		else if (k[1] != -1)
			looking_for_the_number(k, &down, all);
		else if (all->a[0] > 1 && down > 0)
		{
			reverse_rotate(all->a, NULL);
			print_multi("rra");
			all->sorted[0]--;
			down--;
		}
	}
}
