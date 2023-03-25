/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:01:18 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/25 13:18:04 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	exec_command(t_pipex *var, int path_index, int cmd_index, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(var->cmd[cmd_index], ' ');
	cmd_path = ft_strjoin(var->path[path_index], cmd_args[0]);
	if (execve(cmd_path, cmd_args, env) == -1)
		ft_exit("execve", var);
}

int	valid_command(t_pipex *var, int cmd_nb)
{
	int		i;
	char	*cmd;
	char	**temp;

	i = -1;
	temp = ft_split(var->cmd[cmd_nb - 1], ' ');
	while (var->path[++i])
	{
		cmd = ft_strjoin(var->path[i], temp[0]);
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_free(cmd), ft_x2free((void **)temp), i);
		ft_free(cmd);
	}
	return (ft_x2free((void **)temp), 0);
}

void	get_commands(t_pipex *var)
{
	int	i;
	int	i2;

	var->cmd = ft_calloc(var->argc - 2, sizeof(char *));
	if (!var->cmd)
		ft_exit("GET_COMMANDS_MALLOC", var);
	i = 2;
	i2 = 0;
	while (i < var->argc - 1)
	{
		var->cmd[i2] = var->argv[i];
		i2++;
		i++;
	}
}