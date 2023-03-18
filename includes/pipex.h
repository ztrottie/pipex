/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:37:11 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/18 14:51:25 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "common.h"

typedef struct 	s_pipex
{
	char	**path;
	int		infile;
	int		outfile;
}				t_pipex;

void	env_get_path(char **env, t_pipex *pipex);

#endif