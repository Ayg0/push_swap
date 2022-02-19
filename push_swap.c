/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:39:28 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/02/19 16:10:25 by ted-dafi         ###   ########.fr       */
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


void	makelist(int ac, char **av, t_stack *all)
{
	int	i;
	t_list	*temp;
	t_list	*newnode;

	i = 1;
	all->a = ft_lstnew(ft_atoi(av[i]));
	temp = all->a;
	i++;
	while(av[i])
	{
		newnode = ft_lstnew(ft_atoi(av[i]));
		temp->next = newnode;
		temp = temp->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	all;

	makelist(ac, av, &all);
	reverse_rotate(&all.a);
	while (all.a)
	{
		printf("%d\n", all.a->content);
		all.a = all.a->next;
	}
}