/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:34:14 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/27 14:11:48 by ztrottie         ###   ########.fr       */
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

	limiter = var->argv[2];
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
}
