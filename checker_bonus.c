/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:37:55 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 15:33:55 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	which_instruction(char *s)
{
	int	l;

	l = -1;
	l += (ft_strcmp(s, "ra") == 0) * 1;
	l += (ft_strcmp(s, "rb") == 0) * 2;
	l += (ft_strcmp(s, "rr") == 0) * 3;
	l += (ft_strcmp(s, "sa") == 0) * 4;
	l += (ft_strcmp(s, "sb") == 0) * 5;
	l += (ft_strcmp(s, "ss") == 0) * 6;
	l += (ft_strcmp(s, "pa") == 0) * 7;
	l += (ft_strcmp(s, "pb") == 0) * 8;
	l += (ft_strcmp(s, "rra") == 0) * 9;
	l += (ft_strcmp(s, "rrb") == 0) * 10;
	l += (ft_strcmp(s, "rrr") == 0) * 11;
	return (l);
}

int	ft_exit(char *s)
{
	write(2, s, ft_strlen(s));
	exit(2);
}

void	deal_with_it(int instruction, t_all *all)
{
	(instruction == -1) && ft_exit("Error\n");
	(instruction == 0) && rotate(all->a, NULL);
	(instruction == 1) && rotate(all->b, NULL);
	(instruction == 2) && rotate(all->a, NULL) && rotate(all->b, NULL);
	(instruction == 3) && swap(all->a, NULL);
	(instruction == 4) && swap(all->b, NULL);
	(instruction == 5) && swap(all->a, NULL) && swap(all->b, NULL);
	(instruction == 6) && push(all->b, all->a, NULL);
	(instruction == 7) && push(all->a, all->b, NULL);
	(instruction == 8) && reverse_rotate(all->a, NULL);
	(instruction == 9) && reverse_rotate(all->b, NULL);
	(instruction == 10) && reverse_rotate(all->a, NULL)
		&& reverse_rotate(all->b, NULL);
}

int	main(int ac, char **av)
{
	t_all	all;
	char	*s;
	int		instruction;

	make_stack(ac, av, &all, 0);
	s = get_next_line(0, 4);
	while (s)
	{
		instruction = which_instruction(s);
		deal_with_it(instruction, &all);
		free(s);
		s = get_next_line(0, 4);
	}
	if (is_it_sorted(all.a))
		return (write(1, "OK\n", 3));
	return (write(2, "KO\n", 3));
}
