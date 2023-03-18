/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:36:53 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/18 14:55:51 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	get_files(char **argv, t_pipex *var)
{
	var->infile = open(argv[1], O_RDONLY);
	if (var->infile < 0)
		ft_error("Invalid fd");
	var->outfile = open(argv[4], O_RDWR, O_CREAT, O_TRUNC, 0644);
	if (var->outfile < 0)
		ft_error("Invalid fd");
}

int	main(int argc, char **argv, char **env)
{
	t_pipex var;
	
	ft_bzero(var, sizeof(t_pipex));
	if (argc == 5)
	{
		get_files(argv, &var);
	}
	return (0);
}