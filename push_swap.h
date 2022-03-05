/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:07:42 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/04 21:34:58 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_all
{
	int	*a;
	int	*b;
	int	*sorted;
}	t_all;

char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int		ft_atoi(const char *str);
#endif
