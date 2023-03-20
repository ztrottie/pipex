/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:51:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/20 14:39:10 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct 	s_pipex
{
	char	**path;
	char	**argv;
	char	**cmd;
	int		argc;
	int		infile;
	int		outfile;
}				t_pipex;

void	ft_free_all(t_pipex	*var);
void	ft_exit(char *error, t_pipex *var);

#endif