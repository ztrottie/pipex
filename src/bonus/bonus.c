/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:06:00 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/26 16:22:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static void	set_variables(t_pipex *var, int argc, char **argv, char **env)
{
	var->argc = argc;
	var->argv = argv;
	var->env = env;
	get_commands(var);
	var->path = get_path(var->env);
}

static void	child_process(t_pipex *var, int index)
{
	
}

static void	parent_process(t_pipex *var)
{
	
}

static void	pipex(t_pipex *var)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < var->cmd_count)
	{
		pid = fork();
		if (!pid)
			child_process(var);
		else
			pid_add_end(var, pid);
		i++;
	}
	parent_process(var);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	var;

	if (argc < 5)
		return (0);
	set_variables(&var, argc, argv, env);
	for (int i = 0; var.path[i]; i++)
		ft_printf("%s\n", var.path[i]);
}
