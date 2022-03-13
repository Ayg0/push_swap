/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:07:42 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/13 13:14:05 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

#define middli all->middle
#define offseti all->offset

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
#endif
