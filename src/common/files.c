/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/21 14:34:26 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	get_files(char **argv, t_pipex *var)
{
	var->infile = open(argv[1], O_RDONLY);
	var->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (var->infile < 0)
		ft_exit(argv[1], var);
	if (var->outfile < 0)
		ft_exit(argv[4], var);
}