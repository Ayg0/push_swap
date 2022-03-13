/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:40:49 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/13 14:49:32 by ted-dafi         ###   ########.fr       */
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
	if (b == 0)
		return (0);
	while (i)
		((char *)b)[--i] = 0;
	return (b);
}

int	num_of_slots(int ac, char **av)
{
	int		i;
	char	**arr;
	i = 0;
	while (ac > 1)
	{
		arr = ft_split(av[ac - 1], ' ');
		while (*arr)
		{
			arr++;
			i++;
		}
		ac--;
	}
	return (i);
}

void	sort_it(t_all *all)
{
	int	i;
	int	j;

	i = 1;
	while (i < all->sorted[0])
	{
		j = 1;
		while(j < all->sorted[0] - i + 1)
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


void	make_sorted(t_all *all)
{
	int	i;
	int	j;

	i = 0;
    if (all->sorted)
        free(all->sorted);
    all->sorted = (int *)ft_calloc(all->a[0] + 1, sizeof(int));
	while(i < all->a[0] + 1)
	{
		all->sorted[i] = all->a[i];
		j = 1;
		while(j < i)
		{
			if (all->sorted[i] == all->sorted[j])
				exit(write(2, "error\n", 6));
			j++;
		}
		i++;
	}
	sort_it(all);
}

int	is_it_sorted(int *a)
{
	int	i;

	i = 1;
	while(i < a[0])
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
    return (1);
}

void	swap(int *a, char *s)
{
	if (a[0] > 1)
	{
		a[1] ^= a[2];	
		a[2] ^= a[1];	
		a[1] ^= a[2];	
	}
	if (s)
		write(1, s, ft_strlen(s));
}

void	reverse_rotate(int *a, char *s)
{
	int	k;
	int	i;

	k = a[a[0]];
	i = a[0] + 1;
	while(i > 1)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[1] = k;
	if (s)
		write(1, s, ft_strlen(s));
}

void	rotate(int *a, char *s)
{
	int	k;
	int	i;

	k = a[1];
	i = 1;
	while(i < a[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = k;
	if (s)
		write(1, s, ft_strlen(s));
}

void	push(int *from, int *to, char *s)
{
	int	i;

	if (!(from[0] > 0))
		return ;
	to[0]++;
	i = to[0] + 1;
	while(i > 1)
	{
		to[i] = to[i - 1];
		i--;
	}
	to[1] = from[1];
	i = 1;
	while(i < from[0])
	{
		from[i] = from[i + 1];
		i++;
	}
	from[0]--;
	if (s)
		write(1, s, ft_strlen(s));
}


void	make_stack(int ac, char **av, t_all	*all)
{
	int		i;
	int		j;
	char	**arr;

	i = num_of_slots(ac, av);
	all->a = ft_calloc(i + 1, sizeof(int));
	all->b = ft_calloc(i + 1, sizeof(int));
	all->a[0] = i;
	all->b[0] = 0;
	i= 1;
	j = 1;
	while(i < ac)
	{
		arr = ft_split(av[i], ' ');
		while (*arr)
		{
			all->a[j] = ft_atoi(*arr);
			arr++;
			j++;
		}
		i++;
	}
	if (is_it_sorted(all->a))
        exit(0);
    all->sorted = NULL;
	make_sorted(all);
}

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

void	sort_t(t_all *all)
{
	int	i[2];
	if (all->a[0] == 2)
		return (swap(all->a, "sa\n"));
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

int	*make_temp(t_all *all)
{
	int	i;
	int	*temp;

	temp = ft_calloc(all->a[0] + 1, sizeof(int));
	i = 0;
	while (i <= all->a[0])
	{
		temp[i] = all->a[i];
		i++;
	}
	return (temp);
}

int direct(t_all *all, int j)
{
    int i;
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

void    sort_ff(t_all *all)
{
    while(all->a[1] != all->sorted[1])
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

void	sort_thee(t_all *all)
{
	int	i;

	i = all->a[0] - 3;
	while (i)
	{
		if (all->a[1] == all->sorted[1] || all->a[1] == all->sorted[2])
		{
			push(all->a, all->b, "pb\n");
			i--;
			if (!i)
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

int	get_index(t_all *all, int value)
{
	int	i;

	i = 1;
	while (i < all->sorted[0])
	{
		if (all->sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);	
}

void	print_multi(char c1, char c2)
{
	static char s[5];
	int	i;
	
	s[4]++;
	s[0] = s[0] * (s[0] != 0) + c1 * (s[4] == 1);
	s[1] = s[1] * (s[1] != 0) + c2 * (s[4] == 1);
	s[2] = s[2] * (s[0] != 0) + c1 * (s[4] == 2);
	s[3] = s[3] * (s[0] != 0) + c2 * (s[4] == 2);
	if (s[0] && s[2])
	{
		if (s[1] != s[3] && s[0] == s[2] && s[0] != 'p')
			ft_printf("%c%c\n", s[0], s[0]);
		else if (s[3] != 'k')
			ft_printf("%c%c\n%c%c\n", s[0], s[1], s[2], s[3]);
		else
			ft_printf("%c%c\n", s[0], s[1]);
		i = 0;
		while (i < 5)
			s[i++] = 0;
	}
}

void	from_a_to_b(t_all *all, int start, int end)
{
	while (all->a[0])
	{
		end += offseti * (all->a[0] + offseti == all->sorted[0]) + all->sorted[0] * (all->a[0] + offseti > all->sorted[0]);
		start -= end - middli * (end >= middli) + start * (end < middli);
		if (end - (start + get_index(all, all->a[1])) > 0)
		{
			push(all->a, all->b, NULL);
			print_multi('p', 'a');
			if (get_index(all, all->b[1]) > middli)
			{
				rotate(all->b, NULL);
				print_multi('r', 'b');
			}
		}
		else
		{
			rotate(all->a, NULL);
			print_multi('r', 'a');
		}
	}
}

void	just_sort(t_all *all)
{
	int	start;
	int	end;

	all->offset = (all->a[0] <= 150) * (all->a[0] / 8) 
			+ (all->a[0] > 150) * (all->a[0] / 13);
	all->middle = all->sorted[0] / 2;
	start = (middli - offseti) * (middli >= offseti);
	end = (middli + offseti) * (middli + offseti <= all->sorted[0]) +
		all->sorted[0] * (middli + offseti > all->sorted[0]); 
	from_a_to_b(all, start, end);
}

void	sort_that(t_all *all)
{
	// if (all->a[0] <= 3)
	// 	sort_t(all);
	// else if (all->a[0] <= 5)
	// 	sort_f(all);
	// else
	just_sort(all);
}

int	main(int ac, char **av)
{
	t_all	all;

	make_stack(ac, av, &all);
	// push(all.a, all.b);
	// push(all.a, all.b);
	// int	i = 0;
	// while(i < all.sorted[0] + 1)
	// {
	// 	printf("%d\n", all.sorted[i]);
	// 	i++;
	// }
	sort_that(&all);
	// int i = 0;
	// printf("B:\n");
	// while(i < all.b[0] + 1)
	// {
	// 	printf("%d\n", all.b[i]);
	// 	i++;
	// }
}
