/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:20:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/24 16:41:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	get_in_out(t_pipex *var, int index, int end[2])
{
	if (index == 0)
	{
		dup2(var->infile, STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);
	}
	else if (index == var->argc - 2)
	{
		dup2(end[0], STDIN_FILENO);
		dup2(var->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(end[0], STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);
	}
}

void	close_in_out(t_pipex *var, int index, int end[2])
{
	if (index == 0)
	{
		close(var->infile);
		close(end[1]);
	}
	else if (index == var->argc - 2)
	{
		close(end[0]);
		close(var->outfile);
	}
	else
	{
		close(end[0]);
		close(end[1]);
	}
}