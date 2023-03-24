/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:51:44 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/24 16:27:21 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "common.h"

typedef struct	s_pid
{
	pid_t			pid;
	struct s_pid	*next;
}				t_pid;

void	pid_add_end(t_pid **pid_list, pid_t pid);
void	pid_free_list(t_pid **pid_list);
void	get_in_out(t_pipex *var, int index, int end[2]);
void	close_in_out(t_pipex *var, int index, int end[2]);

#endif