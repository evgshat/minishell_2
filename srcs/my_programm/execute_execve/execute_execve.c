/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:04 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:35:05 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	execute_execve_without_path(t_cmd_list *cmd_i,
										char **env, char **path_arr)
{
	char	*tmp;
	char	*final;

	while (*path_arr != NULL)
	{
		tmp = ft_strjoin(*path_arr, "/");
		final = ft_strjoin(tmp, cmd_i->cmnd_words[0]);
		execve(final, cmd_i->cmnd_words, env);
		path_arr++;
		ft_free_str(&tmp);
		ft_free_str(&final);
	}
	return (0);
}

int	execute_execve_with_path(t_cmd_list *cmd_i, char **env)
{
	execve(cmd_i->cmnd_words[0], cmd_i->cmnd_words, env);
	return (0);
}

int	execute_execve(t_cmd_list *cmd_i, t_main *prmtrs)
{
	char	**env;
	char	*paths;
	char	**path_arr;

	env = env_create_arr(prmtrs->env_head);
	paths = getvalue_env_lst("PATH", prmtrs->env_head);
	path_arr = ft_split(paths, ':');
	if ((ft_strlen(cmd_i->cmnd_words[0]) > 2)
		&& (cmd_i->cmnd_words[0][0] == '/' || cmd_i->cmnd_words[0][0] == '.'))
	{
		execute_execve_with_path(cmd_i, env);
	}
	else
	{
		execute_execve_without_path(cmd_i, env, path_arr);
	}
	ft_free_str(&paths);
	ft_free_str_arr(&env);
	ft_free_str_arr(&path_arr);
	printf("my_shell: %s: command not found\n", cmd_i->cmnd_words[0]);
	prmtrs->exit_status = 127;
	exit(prmtrs->exit_status);
	return (0);
}
