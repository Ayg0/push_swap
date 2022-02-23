/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:39:28 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:14 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	that_phrase(char *s)
{
	write(1, s, ft_strlen(s));
}
void	swap(t_list **a, char *s)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (s)
		write(1, s, ft_strlen(s));
}

void	rotate(t_list **a, char *s)
{
	t_list	*temp;

	if (*a)
	{
		temp = ft_lstlast(*a);
		temp->next = *a;
		*a = (*a)->next;
		temp->next->next = NULL;
		if (s)
			write(1, s, ft_strlen(s));
	}
}

void	push(t_stack *all, int flag, char *s)
{
	t_list	*temp;

	if (flag && all->a)
	{
		temp = all->a->next;
		ft_lstadd_front(&(all->b), all->a);
		all->a = temp;
		if (s)
			write(1, s, ft_strlen(s));
	}
	else if (all->b && !flag)
	{
		temp = all->b->next;
		ft_lstadd_front(&(all->a), all->b);
		all->b = temp;
		if (s)
			write(1, s, ft_strlen(s));
	}
}

t_list	*beforeit(t_list *a)
{
	while (a->next->next)
		a = a->next;
	return (a);
}

void	reverse_rotate(t_list **a, char *s)
{
	t_list	*temp;
	t_list	*temp2;

	if (*a)
	{
		temp = beforeit(*a);
		temp2 = ft_lstlast(*a);
		ft_lstlast(*a)->next = *a;
		*a = temp2;
		temp->next = NULL;
		if (s)
			write(1, s, ft_strlen(s));
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

int	check_for_dub(t_list *a, int value)
{
	int	i = 1;
	while(a)
	{
		if (a->content == value)
			i--;
		a = a->next;
	}
	return (1);
}

void	full_in(t_stack *all, t_list **temp, char **arr, int flag)
{
	int	j;
	j = flag;
	while (arr[j])
	{
		(*temp)->next = ft_lstnew(ft_atoi(arr[j]));
		*temp = (*temp)->next;
		j++;
	}
}

void	makelist(int ac, char **av, t_stack *all)
{
	int	i;
	char	**arr;
	t_list	*temp;

	i = 1;
	arr = ft_split(av[i], ' ');
	all->a = ft_lstnew(ft_atoi(arr[0]));
	temp = all->a;
	full_in(all, &temp, arr, 1);
	i++;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		full_in(all, &temp, arr, 0);
		i++;
	}
}

int	sorted(t_list *a)
{
	int	l;
	t_list	*temp;

	l = 1;
	temp = a;
	while(a->next)
	{
		if (a->content > a->next->content)
			l = 0;
		if (check_for_dub(temp, a->content) == -1)
			exit(write(2, "error\n", 7));
		a = a->next;
	}
	return (l);
}

void	which_which(t_list *a, int *small, int *big)
{
	int	i[2];
	int	k;

	k = 1;
	i[0] = a->content;
	i[1] = -1;
	while(a)
	{
		if (a->content > i[1])
		{
			i[1] = a->content;
			*big = k;
		}
		if (a->content < i[0])
		{
			i[0] = a->content;
			*small = k;
		}
		k++;
		a = a->next;
	}
}

void	sort_t(t_stack *all, int size)
{
	int	i[2];

	if (size == 2)
		swap(&all->a, "sa\n");
	else
	{
		which_which(all->a, &i[0], &i[1]);
		if (i[0] == 1 && i[1] == 2)
		{
			reverse_rotate(&all->a, "rra\n");
			swap(&all->a, "sa\n");
		}
		else if (i[0] == 2 && i[1] == 3)
			swap(&all->a, "sa\n");	
		else if (i[0] == 3 && i[1] == 1)
		{
			rotate(&all->a, "ra\n");
			swap(&all->a, "sa\n");
		}
		else if (i[0] == 2 && i[1] == 1)
			rotate(&all->a, "ra\n");
		else
			reverse_rotate(&all->a, "rra\n");
	}
}

void	sort_f(t_stack *all, int size)
{
	while(size != 3)
	{
		push(all, 1, "pb\n");
		size--;
	}
	sort_t(all, 3);
	push(all, 0, "pa\n");
	// if (!sorted(all->a))
	// 	sort_t
	// if (all->b)
	// 	push(all, 0, "pa\n");
	// else
		exit(0);
	
}

void	swap_arr(int *a, int *b)
{
	*a ^= *b;	
	*b ^= *a;	
	*a ^= *b;	
}

void	that_arr(t_stack *all, int size)
{
	int	i;
	int	j;
	t_list	*temp;

	i = 1;
	all->sorted = (int *)malloc(sizeof(int) * (size + 1));
	all->sorted[0] = size + 1;
	temp = all->a;
	while(temp)
	{
		all->sorted[i] = temp->content;
		i++;
		temp = temp->next;
	}
	i = 1;
	while(i < size)
	{
		j = 0;
		while(j < size - i)
		{
			if (all->sorted[i] > all->sorted[i + 1])
				swap_arr(&all->sorted[i], &all->sorted[i + 1]);
			j++;
		}
		i++;
	}
}

void	ft_sort(t_stack	*all)
{
	int	size;
	size = ft_lstsize(all->a);
	if (size <= 3)
		sort_t(all, size);
	that_arr(all, size);
}
int	main(int ac, char **av)
{
	t_stack	all;

	makelist(ac, av, &all);
	if (sorted(all.a))
		return (0);
	ft_sort(&all);
	while(all.a)
	{
		printf("%d\n", all.a->content);
		all.a = all.a->next;
	}
	printf("----------\n");
	int i = 1;
	while(i < all.sorted[0])
	{
		printf("%d\n", all.sorted[i]);
		i++;
	}
}