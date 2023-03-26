/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:12:02 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/26 15:37:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static int	get_start(t_pipex *var)
{
	if (ft_strncmp(var->argv[1], "here_doc\0", 8) == 0)
	{
		var->cmd = ft_calloc(var->argc - 4, sizeof(char *));
		return (3);
	}
	else
	{
		var->cmd = ft_calloc(var->argc - 3, sizeof(char *));
		return (2);
	}
}

void	get_commands(t_pipex *var)
{
	int	i;
	int	start;

	start = get_start(var);
	i = 0;
	while (i < var->argc - start - 1)
	{
		var->cmd[i] = var->argv[i + start];
		i++;
	}
	var->cmd_count = i;
}
