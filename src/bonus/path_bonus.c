/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:21:28 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/26 15:34:04 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i]);
		i++;
	}
	perror("NO PATH");
	exit(errno);
}

static void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		ft_free(temp[i]);
		i++;
	}
	ft_free(temp);
}

char	**get_path(char **env)
{
	int		i;
	char	*path_str;
	char	**my_path;
	char	**temp;

	path_str = find_path(env);
	if (path_str == NULL)
		return (NULL);
	temp = ft_split(path_str + 5, ':');
	my_path = ft_calloc(ft_word_count(path_str, ':'), sizeof(char *));
	i = 0;
	while (temp[i])
	{
		my_path[i] = ft_strjoin(temp[i], "/");
		i++;
	}
	free_temp(temp);
	return (my_path);
}
