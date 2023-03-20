/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:36:53 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/20 14:45:33 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	get_files(char **argv, t_pipex *var)
{
	var->infile = open(argv[1], O_RDONLY);
	if (var->infile < 0)
		ft_exit("Invalid fd(infile)", var);
	var->outfile = open(argv[4], O_RDWR, O_CREAT, O_TRUNC, 0644);
	if (var->outfile < 0)
		ft_exit("Invalid fd(outfile)", var);
}

static char *find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

static char	**get_path(char **env)
{
	char *path_str;

	path_str = find_path(env);
	if (path_str == NULL)
		return (NULL);
	return (ft_split(path_str + 5, ':'));
}

static void set_variables(t_pipex *var, int argc, char **argv, char **env)
{
	ft_bzero(var, sizeof(t_pipex));
	var->argv = argv;
	var->argc = argc;
	var->path = get_path(env);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex var;
	int		i;
	
	i = 0;
	if (argc == 5)
	{
		set_variables(&var, argc, argv, env);
		if (var.path == NULL)
			ft_exit("PATH ERROR", &var);
		get_files(argv, &var);
		close(var.infile);
		close(var.outfile);
	}
	return (ft_free_all(&var), 0);
}