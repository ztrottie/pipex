/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:36:53 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/25 16:12:39 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

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

static void	child_process(t_pipex *var, int	end[2], char **env)
{
	int	cmd_path_index;

	if (dup2(var->infile, STDIN_FILENO) < 0)
		ft_exit("dup2:", var);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		ft_exit("dup2:", var);
	close(end[0]);
	close(var->infile);
	cmd_path_index = valid_command(var, 1);
	if (cmd_path_index > 0)
		exec_command(var, cmd_path_index, 0, env);
	else
		exit(0);
}

static void	parent_process(t_pipex *var, int end[2], char **env)
{
	int	cmd_path_index;

	if (dup2(var->outfile, STDOUT_FILENO) < 0)
		ft_exit("dup2:", var);
	if (dup2(end[0], STDIN_FILENO) < 0)
		ft_exit("dup2:", var);
	close(end[1]);
	close(var->outfile);
	cmd_path_index = valid_command(var, 2);
	if (cmd_path_index > 0)
		exec_command(var, cmd_path_index, 1, env);
	else
		exit(0);
}

static void	pipex(t_pipex *var, char **env)
{
	int		end[2];
	pid_t	pid;

	pipe(end);
	pid = fork();
	if (pid < 0)
		ft_exit("FORK:", var);
	if (!pid)
		child_process(var, end, env);
	else
		parent_process(var, end, env);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex var;

	if (argc != 5)
		return (0);
	set_variables(&var, argc, argv, env);
	get_files(argv, &var, 0);
	pipex(&var, env);
	return (ft_free_all(&var), 0);
}