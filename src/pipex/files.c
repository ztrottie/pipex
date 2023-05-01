/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/01 14:41:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	close_all(t_pipex *var, int end[2])
{
	close(var->infile);
	close(var->outfile);
	close(end[0]);
	close(end[1]);
}

void	get_files(char **argv, t_pipex *var)
{
	var->outfile = open(argv[var->argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	var->infile = open(argv[1], O_RDONLY);
	if (var->outfile < 0)
		ft_exit(argv[var->argc - 1], var);
}
