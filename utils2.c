/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:26:02 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 13:46:56 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_which(t_all *all, int *small, int *big)
{
	int	i;

	i = 1;
	while (i < all->a[0] + 1)
	{
		if (all->a[i] == all->sorted[1])
			*small = i;
		else if (all->a[i] == all->sorted[3])
			*big = i;
		i++;
	}
}

void	sort_that(t_all *all)
{
	if (all->a[0] <= 3)
		sort_t(all);
	else if (all->a[0] <= 5)
		sort_f(all);
	else
		just_sort(all);
}
