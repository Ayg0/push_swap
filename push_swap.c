/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:39:28 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/02/21 21:00:23 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	rotate(t_list **a)
{
	t_list	*temp;

	if (*a)
	{
		temp = ft_lstlast(*a);
		temp->next = *a;
		*a = (*a)->next;
		temp->next->next = NULL;
	}
}

void	push(t_stack *all, int flag)
{
	t_list	*temp;

	if (flag && all->a)
	{
		temp = all->a->next;
		ft_lstadd_front(&(all->b), all->a);
		all->a = temp;
	}
	else if (all->b && !flag)
	{
		temp = all->b->next;
		ft_lstadd_front(&(all->a), all->b);
		all->b = temp;
	}
}

t_list	*beforeit(t_list *a)
{
	while (a->next->next)
		a = a->next;
	return (a);
}

void	reverse_rotate(t_list **a)
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
	}
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

void	check_for_dub(int ac, char **av, int **arr)
{
	int	i;
	int	j;

	i = 0;
	*arr = (int	*)ft_calloc(ac, sizeof(int));
	if (!(*arr))
		exit(write(2, "couldn't allocate\n", 18));
	while(i < ac - 1)
	{
		(*arr)[i] = ft_atoi(av[i + 1]);
		j = 0;
		while(j < i)
		{
			if ((*arr)[i] == (*arr)[j])
				exit(write(2, "a wa3r nta dayr liya double\n", 29));
			j++;
		}
		i++;
	}
}

void	makelist(int ac, char **av, t_stack *all)
{
	int	i;
	int	*arr;
	t_list	*temp;
	t_list	*newnode;

	check_for_dub(ac, av, &arr);
	i = 0;
	all->a = ft_lstnew(arr[i]);
	temp = all->a;
	i++;
	while(arr[i])
	{
		newnode = ft_lstnew(arr[i]);
		temp->next = newnode;
		temp = temp->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	all;

	makelist(ac, av, &all);
	push(&all, 1);
	push(&all, 1);
	push(&all, 1);
	while (all.b)
	{
		printf("%d\n", all.b->content);
		all.b = all.b->next;
	}
}