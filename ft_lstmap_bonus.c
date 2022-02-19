/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:58:13 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/02/19 15:32:54 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, int	(*f)(int), void *(*del)(int))
{
	t_list	*newlst;
	t_list	*follow;

	if (!lst)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (!newlst)
		return (NULL);
	follow = newlst;
	lst = lst->next;
	while (lst)
	{
		follow->next = ft_lstnew(f(lst->content));
		if (!(follow->next))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		follow = follow->next;
		lst = lst->next;
	}
	return (newlst);
}
