/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:35:23 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/27 16:34:53 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	close_all(t_pipex *var)
{
	int	i;
	
	close(var->infile);
	close(var->outfile);
	i = 0;
	while (i < var->cmd_count - 1)
	{
		close(var->pipe[i][0]);
		close(var->pipe[i][1]);
		i++;
	}
}

void	get_in_out(t_pipex *var, int index)
{
	if (index == 0)
	{
		if (var->infile < 0)
			ft_exit(var->argv[1], var);
		dup2(var->infile, STDIN_FILENO);
		dup2(var->pipe[index][1], STDOUT_FILENO);
	}
	else if (index < var->cmd_count - 1)
	{
		dup2(var->pipe[index - 1][0], STDIN_FILENO);
		dup2(var->pipe[index][1], STDOUT_FILENO);
	}
	else
	{
		dup2(var->pipe[index - 1][0], STDIN_FILENO);
		dup2(var->outfile, STDOUT_FILENO);
	}
	close_all(var);
}

void	open_fd(t_pipex *var)
{
	if (ft_strncmp(var->argv[1], "here_doc\0", 9) == 0)
	{
		var->outfile = open(var->argv[var->argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		if (var->outfile < 0)
			ft_exit(var->argv[var->argc - 1], var);
		var->infile = open("/tmp/.infile", O_RDWR | O_CREAT);
		var->here_doc = 1;
	}
	else
	{
		var->outfile = open(var->argv[var->argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (var->outfile < 0)
			ft_exit(var->argv[var->argc - 1], var);
		var->infile = open(var->argv[1], O_RDONLY);
	}
}

void	get_pipes(t_pipex *var)
{
	int	i;

	var->pipe = ft_calloc(var->cmd_count - 1, sizeof(int *));
	i = 0;
	while (i < var->cmd_count - 1)
	{
		var->pipe[i] = ft_calloc(2, sizeof(int));
		pipe(var->pipe[i]);
		i++;
	}
}
