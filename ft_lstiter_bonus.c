/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:20:54 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/02/19 15:35:55 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_list *lst, int (*f)(int))
{
	if (!lst)
		return ;
	while (lst)
	{
		f((lst->content));
		lst = lst->next;
	}
}
