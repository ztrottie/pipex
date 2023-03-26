/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:51:44 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/26 15:36:20 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pid
{
	pid_t			pid;
	struct s_pid	*next;
}				t_pid;

typedef struct s_pipex
{
	char			**path;
	char			**argv;
	char			**cmd;
	char			**env;
	int				**pipe;
	int				cmd_count;
	int				argc;
	int				infile;
	int				outfile;
	struct s_pid	*pid_list;
}				t_pipex;

void	get_commands(t_pipex *var);
char	**get_path(char **env);

#endif