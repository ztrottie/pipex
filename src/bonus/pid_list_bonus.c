/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:47:45 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/27 14:38:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	pid_list_free(t_pipex *var)
{
	t_pid	*ptr;
	t_pid	*temp;

	ptr = var->pid_list;
	while (ptr->next != NULL)
	{
		temp = ptr->next;
		ft_free(ptr);
		ptr = temp;
	}
}

void	pid_add_end(t_pipex *var, pid_t pid)
{
	t_pid	*ptr;

	if (var->pid_list == 0)
	{
		var->pid_list = ft_calloc(1, sizeof(t_pid *));
		var->pid_list->pid = pid;
		var->pid_list->next = NULL;
	}
	else
	{
		ptr = var->pid_list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_pid *));
		ptr->next->pid = pid;
		ptr->next->next = NULL;
	}
}
