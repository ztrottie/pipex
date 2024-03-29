/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:37:11 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/28 13:36:26 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**path;
	char	**argv;
	char	**cmd;
	char	**env;
	int		argc;
	int		infile;
	int		outfile;
}				t_pipex;

void	get_files(char **argv, t_pipex *var);
void	ft_free_all(t_pipex	*var);
void	ft_exit(char *error, t_pipex *var);
void	get_commands(t_pipex *var);
char	**get_path(char **env);
int		valid_command(t_pipex *var, int cmd_nb);
void	exec_command(t_pipex *var, int path_index, int cmd_index, char **env);
void	close_all(t_pipex *var, int end[2]);

#endif