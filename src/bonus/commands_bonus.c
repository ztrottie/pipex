/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:12:02 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/27 12:22:31 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	exec_command(t_pipex *var, int path_index, int cmd_index)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(var->cmd[cmd_index], ' ');
	cmd_path = ft_strjoin(var->path[path_index], cmd_args[0]);
	if (execve(cmd_path, cmd_args, var->env) == -1)
		perror("EXECVE");
}

int	valid_command(t_pipex *var, int cmd_nb)
{
	int		i;
	char	*cmd;
	char	**temp;

	i = 0;
	temp = ft_split(var->cmd[cmd_nb], ' ');
	while (var->path[i])
	{
		cmd = ft_strjoin(var->path[i], temp[0]);
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_free(cmd), ft_x2free((void **)temp), i);
		ft_free(cmd);
		i++;
	}
	return (ft_x2free((void **)temp), -1);
}

static int	get_start(t_pipex *var)
{
	if (var->here_doc == 1)
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
