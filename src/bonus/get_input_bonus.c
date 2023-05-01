/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:34:14 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/01 14:48:50 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	get_input(t_pipex *var)
{
	char	*limiter;
	char	*str;
	int		limiter_len;
	int		run;
	int		comp;

	var->infile = open("/tmp/.infile", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (var->infile < 0)
		ft_exit("here_doc", var);
	limiter = ft_strjoin(var->argv[2], "\n");
	limiter_len = ft_strlen(limiter);
	str = NULL;
	run = 1;
	while (run)
	{
		str = get_next_line(0);
		comp = ft_strncmp(limiter, str, limiter_len);
		if (comp != 0)
			ft_putstr_fd(str, var->infile);
		else if (comp == 0 || str == NULL)
			run = 0;
		ft_free(str);
	}
	close(var->infile);
}
