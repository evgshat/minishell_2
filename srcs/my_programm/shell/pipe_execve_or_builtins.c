/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execve_or_builtins.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:34:12 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:58:54 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	pipe_execve_or_builtins(t_cmd_list *cmd_i, t_main *prmts)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		exit(free_prmtrs(prmts, ERROR));
	}
	else if (pid == 0)
	{
		red_cmd_fd(cmd_i);
		execute_execve(cmd_i, prmts);
		free_prmtrs(prmts, 0);
	}
	else
	{
		waitpid(pid, &(prmts->exit_status), 0);
		prmts->exit_status = WEXITSTATUS(prmts->exit_status);
	}
	return (0);
}
