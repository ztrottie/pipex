/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:09:57 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/25 14:56:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	get_in_out(t_pipex *var, int index)
{
	if (index == 0)
	{
		dup2(var->infile, STDIN_FILENO);
		dup2(var->pipe[index][1], STDOUT_FILENO);
		close(var->pipe[index][0]);
		close(var->infile);
	}
	else if (index > 0 && index < var->argc - 4)
	{
		dup2(var->pipe[index - 1][0], STDIN_FILENO);
		dup2(var->pipe[index][1], STDOUT_FILENO);
		close(var->pipe[index - 1][1]);
		close(var->pipe[index][0]);
	}
	else
	{
		dup2(var->pipe[index - 1][0], STDIN_FILENO);
		dup2(var->outfile, STDOUT_FILENO);
		close(var->pipe[index - 1][1]);
		close(var->outfile);
	}
	for (int i = 0; i < var->argc - 4; i++)
    {
        if (i != index - 1 && i != index)
        {
            close(var->pipe[i][0]);
            close(var->pipe[i][1]);
        }
    }
}

void	close_all(t_pipex *var)
{
	close(var->infile);
	close(var->outfile);
	for (int i = 0; i < var->argc - 4; i++)
	{
		close(var->pipe[i][0]);
		close(var->pipe[i][1]);
	}
}
