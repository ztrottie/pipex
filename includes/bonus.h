/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:51:44 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/27 14:32:16 by ztrottie         ###   ########.fr       */
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
# include <sys/wait.h>
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
	int				here_doc;
	int				cmd_count;
	int				argc;
	int				infile;
	int				outfile;
	struct s_pid	*pid_list;
}				t_pipex;

void	get_commands(t_pipex *var);
char	**get_path(char **env);
int		valid_command(t_pipex *var, int cmd_nb);	
void	exec_command(t_pipex *var, int path_index, int cmd_index);
void	pid_add_end(t_pipex *var, pid_t pid);
void	pid_list_free(t_pipex *var);
void	get_pipes(t_pipex *var);
void	close_all(t_pipex *var);
void	get_in_out(t_pipex *var, int index);
void	open_fd(t_pipex *var);
void	get_input(t_pipex *var);
void	ft_exit(char *error, t_pipex *var);

#endif