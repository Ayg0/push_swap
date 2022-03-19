/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:07:42 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 22:54:56 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_all
{
	int	*a;
	int	*b;
	int	*sorted;
	int	offset;
	int	middle;
}	t_all;

char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int		ft_atoi(const char *str);
int		num_of_slots(int ac, char **av);
void	sort_it(t_all *all);
void	make_sorted(t_all *all);
int		is_it_sorted(int *a);
int		swap(int *a, char *s);
int		reverse_rotate(int *a, char *s);
int		rotate(int *a, char *s);
int		push(int *from, int *to, char *s);
void	make_stack(int ac, char **av, t_all	*all, int flag);
void	which_which(t_all *all, int *small, int *big);
void	sort_t(t_all *all);
int		*make_temp(t_all *all);
int		direct(t_all *all, int j);
void	sort_ff(t_all *all);
void	sort_thee(t_all *all);
void	sort_f(t_all *all);
int		get_index(int *stack, int value);
int		cases_of_multi(char *s);
void	print_multi(char *s2);
void	who_will_go(t_all *all, int *down);
int		play_with_values(t_all *all, int *start, int *end);
void	from_a_to_b(t_all *all, int start, int end);
void	from_b_to_a(t_all *all);
void	just_sort(t_all *all);
void	sort_that(t_all *all);
void	looking_for_the_number(int *k, int *down, t_all *all);
void	up_down(char *s2, char *s3, int *l);
void	why_r_ya_running(char **d, int i);
#endif
