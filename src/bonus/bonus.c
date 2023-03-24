/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:36:53 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/24 16:33:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static void set_variables(t_pipex *var, int argc, char **argv, char **env)
{
	ft_bzero(var, sizeof(t_pipex));
	var->argv = argv;
	var->argc = argc;
	var->path = get_path(env);
	if (var->path == NULL)
		ft_exit("PATH", var);
	get_commands(var);
}

static void	child_process(t_pipex *var, char **env, int index)
{
	int	end[2];
	int cmd_path_index;

	pipe(end);
	get_in_out(var, index, end);
	close_in_out(var, index, end);
	cmd_path_index = valid_command(var, index);
	if (cmd_path_index > 0)
		exec_command(var, cmd_path_index, index, env);
	else
		exit(0);
}

static void	parent_process(t_pipex *var, t_pid *pid_list)
{
	t_pid	*ptr;
	int		status;

	ptr = pid_list;
	while (ptr != NULL)
	{
		waitpid(ptr->pid, &status, 0);
		ptr = ptr->next;
	}
	pid_free_list(&pid_list);
	ft_free_all(var);
	exit(0);
}

static void	pipex(t_pipex *var, char **env)
{
	t_pid	*pid_list;
	int		pid;
	int		i;

	i = -1;
	pid_list = 0;
	while (++i < var->argc - 2)
	{
		pid = fork();
		if (pid < 0)
			perror("fork");
		if (!pid)
			child_process(var, env, i);
		else
		{
			pid_add_end(&pid_list, pid);
			parent_process(var, pid_list);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex var;

	if (argc < 5)
		return (0);
	set_variables(&var, argc, argv, env);
	get_files(argv, &var);
	pipex(&var, env);
	return (ft_free_all(&var), 0);
}