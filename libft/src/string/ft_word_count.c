/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:25:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/26 15:36:43 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;
	int		trigger;

	i = 0;
	trigger = 1;
	count = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if ((s[i] == c || s[i] == 0) && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		else if (s[i] != c && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count + 1);
}
