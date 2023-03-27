/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:06:00 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/27 16:34:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static void	set_variables(t_pipex *var, int argc, char **argv, char **env)
{
	ft_bzero(var, sizeof(t_pipex));
	var->argc = argc;
	var->argv = argv;
	var->env = env;
	open_fd(var);
	if (var->here_doc == 1)
		get_input(var);
	get_commands(var);
	var->path = get_path(var->env);
	if (var->path == NULL)
		ft_exit("PATH", var);
}

static void	child_process(t_pipex *var, int index)
{
	int	path_index;

	path_index = valid_command(var, index);
	get_in_out(var, index);
	if (path_index != -1)
		exec_command(var, path_index, index);
	else
		ft_exit(var->cmd[index], var);
}

static void	parent_process(t_pipex *var)
{
	t_pid	*ptr;
	int		status;

	ptr = var->pid_list;
	close_all(var);
	if (var->here_doc)
		unlink("/tmp/.infile");
	while (ptr != NULL)
	{
		waitpid(ptr->pid, &status, 0);
		ptr = ptr->next;
	}
	ft_exit(NULL, var);
}

static void	pipex(t_pipex *var)
{
	int		i;
	pid_t	pid;

	i = 0;
	get_pipes(var);
	while (i < var->cmd_count)
	{
		pid = fork();
		if (pid < 0)
			ft_exit("fork", var);
		if (!pid)
			child_process(var, i);
		else
			pid_add_end(var, pid);
		i++;
	}
	parent_process(var);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	var;
	int		argc_limit;

	if (ft_strncmp(argv[1], "here_doc\0", 9) == 0)
		argc_limit = 6;
	else
		argc_limit = 5;
	if (argc < argc_limit)
		return (0);
	set_variables(&var, argc, argv, env);
	pipex(&var);
}
