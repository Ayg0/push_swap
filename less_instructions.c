/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:32:00 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 12:06:47 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int *stack, int value)
{
	int	i;

	i = 1;
	while (i <= stack[0])
	{
		if (stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	cases_of_multi(char *s)
{
	int	i;

	i = 0;
	if (s[0] == s[4] && s[0] != 'p' && s[1] != 'r' && s[1] != s[5])
		ft_printf("%c%c\n", s[0], s[0]);
	else if (s[0] == s[4] && s[0] != 'p' && s[1] == s[5]
		&& s[1] == 'r' && s[2] != s[6])
		ft_printf("rrr\n");
	else
		ft_printf("%s\n%s\n", s, s + 4);
	return (1);
}

void	up_down(char *s2, char *s3, int *l)
{
	if (s2[0] == 'k')
	{
		if (s3[0] && s3[0] != 'k')
			*l = ft_printf("%s\n", s3);
	}
	else if (s3[0] && s3[4])
		*l = cases_of_multi(s3);
}

void	print_multi(char *s2)
{
	static char	s[9];
	char		s3[9];
	int			i;
	int			l;

	s[8]++;
	s[0] += s2[0] * (s[8] == 1);
	s[1] += s2[1] * (s[8] == 1);
	s[2] += s2[2] * (s[8] == 1);
	s[4] += s2[0] * (s[8] == 2);
	s[5] += s2[1] * (s[8] == 2);
	s[6] += s2[2] * (s[8] == 2);
	l = 0;
	i = -1;
	while (++i < 9)
		s3[i] = s[i];
	up_down(s2, s3, &l);
	i = 0;
	while (i < 9 && l)
		s[i++] = 0;
}

void	just_sort(t_all *all)
{
	int	start;
	int	end;

	if (all->a[0] <= 50)
		all->offset = all->a[0] / 4;
	else
		all->offset = (all->a[0] <= 150) * (all->a[0] / 8)
			+ (all->a[0] > 150) * (all->a[0] / 20);
	all->middle = all->sorted[0] / 2;
	start = all->middle - all->offset;
	end = all->middle + all->offset;
	from_a_to_b(all, start, end);
	from_b_to_a(all);
	print_multi("kk");
}
