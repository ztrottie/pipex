/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:03:46 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/20 14:37:09 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/common.h"

void	ft_free_all(t_pipex	*var)
{
	int	i;

	i = 0;
	while (var->path[i])
	{
		ft_free(var->path[i]);
		i++;
	}
	ft_free(var->path);
}

void	ft_exit(char *error, t_pipex *var)
{
	ft_free_all(var);
	perror(error);
	exit(errno);
}