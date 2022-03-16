/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:34:08 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:17:30 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	my_shell_execute(t_cmd_list *cmd_i, t_main *prmts)
{
	if (cmd_i->is_builtin == true)
	{
		cmd(cmd_i, prmts);
	}
	else
	{
		pipe_execve_or_builtins(cmd_i, prmts);
	}
	return (0);
}
