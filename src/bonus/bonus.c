/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:36:53 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/25 15:54:23 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static void set_variables(t_pipex *var, int argc, char **argv, char **env)
{
	int	i;
	
	ft_bzero(var, sizeof(t_pipex));
	var->argv = argv;
	var->argc = argc;
	var->path = get_path(env);
	if (var->path == NULL)
		ft_exit("PATH", var);
	var->pipe = ft_calloc(argc - 4, sizeof(int *));
	i = -1;
	while (++i < var->argc - 4)
		var->pipe[i] = ft_calloc(2, sizeof(int));
	get_commands(var);
}

static void	child_process(t_pipex *var, char **env, int index)
{
	int cmd_path_index;

	get_in_out(var, index);
	cmd_path_index = valid_command(var, index + 1);
	if (cmd_path_index > 0)
		exec_command(var, cmd_path_index, index, env);
	else
		ft_exit(var->cmd[index], var);
}

static void parent_process(t_pipex *var, t_pid *pid_list)
{
    t_pid *ptr;
    int status;

    ptr = pid_list;
	close_all(var);
    while (ptr != NULL)
    {
        if (waitpid(ptr->pid, &status, 0) == -1)
        {
            pid_free_list(&pid_list);
            ft_exit("waitpid", var);
        }
        ptr = ptr->next;
	}
    pid_free_list(&pid_list);
    ft_free_all(var);
    exit(0);
}

static void	get_pipes(t_pipex *var)
{
	int	i;

	i = -1;
	while (++i < var->argc - 4)
	{
		if (pipe(var->pipe[i]) == -1)
			ft_exit("pipe", var);
	}
}

static void	pipex(t_pipex *var, char **env)
{
	t_pid	*pid_list;
	int		pid;
	int		i;

	i = -1;
	pid_list = 0;
	get_pipes(var);
	while (++i < var->argc - 3)
	{
		pid = fork();
		if (!pid)
			child_process(var, env, i);
		else
			pid_add_end(&pid_list, pid);
	}
	parent_process(var, pid_list);
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