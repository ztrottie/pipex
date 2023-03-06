/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:11:40 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 16:39:56 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "memory.h"
# include "string.h"

char	*get_next_line(int fd);
void	*ft_get_bzero(void *p, size_t size);
char	*ft_get_strjoin(char *s1, char *s2);

#endif
