/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:39:15 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/02/23 11:45:22 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}	t_list;

typedef	struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		*sorted;
}	t_stack;
t_list	*ft_lstnew(int	content);
t_list	*ft_lstmap(t_list *lst, int	(*f)(int), void *(*del)(int));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, int	(*f)(int));
void	ft_lstclear(t_list **lst, void *(*del)(int));
void	ft_lstdelone(t_list *lst, void *(*del)(int));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
#endif
