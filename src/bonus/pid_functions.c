/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:28:24 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/24 16:39:04 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	pid_free_list(t_pid **pid_list)
{
	t_pid	*ptr;
	t_pid	*temp;

	ptr = *pid_list;
	while (ptr != NULL)
	{
		temp = ptr->next;
		ft_free(ptr);
		ptr = temp;
	}
}

void	pid_add_end(t_pid **pid_list, pid_t pid)
{
	t_pid	*ptr;
	t_pid	*new;

	if (!*pid_list)
	{
		*pid_list = ft_calloc(1, sizeof(t_pid));
		(*pid_list)->pid = pid;
		(*pid_list)->next = NULL;
	}
	else
	{
		ptr = *pid_list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		new = ft_calloc(1, sizeof(t_pid));
		ptr->next = new;
		new->next = NULL;
		new->pid = pid;
	}
}