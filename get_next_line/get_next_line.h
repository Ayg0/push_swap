/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:58:37 by ted-dafi          #+#    #+#             */
/*   Updated: 2022/03/19 11:50:59 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../push_swap.h"
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char **s1, char *s2);
int		ft_newlchr(const char *s);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd, int BUFFER_SIZE);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*my_free(char **buff, char **temp, int flag);
#endif