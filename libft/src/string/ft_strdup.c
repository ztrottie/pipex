/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:51:14 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:15:33 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"
#include "../../includes/memory.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
