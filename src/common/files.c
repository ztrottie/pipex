/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/25 16:21:05 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	get_files(char **argv, t_pipex *var)
{
	if (ft_strncmp(argv[1], "here_doc\0", 8) != 0)
	{
		var->outfile = open(argv[var->argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		var->infile = open(argv[1], O_RDONLY);
		if (var->infile < 0)
			ft_exit(argv[1], var);
	}
	else
		var->outfile = open(argv[var->argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (var->outfile < 0)
		ft_exit(argv[var->argc - 1], var);
}