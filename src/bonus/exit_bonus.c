/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:12:32 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/27 14:44:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static void	free_all(t_pipex *var)
{
	int	i;
	
	if (var->pid_list != NULL)
		pid_list_free(var);
	ft_free(var->cmd);
	ft_x2free((void **)var->path);
	i = -1;
	while (++i < var->cmd_count - 1)
		ft_free(var->pipe[i]);
	ft_free(var->pipe);
}

void	ft_exit(char *error, t_pipex *var)
{
	free_all(var);
	if (error != NULL)
	{
		perror(error);
		exit(errno);
	}
	else
		exit(0);
}
