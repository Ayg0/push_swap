/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:40:49 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/05 15:11:34 by ted-dafi         ###   ########.fr       */
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

void	is_it_sorted(int *a)
{
	int	i;

	i = 1;
	while(i < a[0])
	{
		if (a[i] > a[i + 1])
			return ;
		i++;
	}
	exit(0);
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
	is_it_sorted(all->a);
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

void	sort_that(t_all *all)
{
	if (all->a[0] <= 3)
		sort_t(all);
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
	// i = 0;
	// printf("B:\n");
	// while(i < all.b[0] + 1)
	// {
	// 	printf("%d\n", all.b[i]);
	// 	i++;
	// }
	sort_that(&all);
}
