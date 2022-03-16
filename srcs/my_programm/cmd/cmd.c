/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:02 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:17:08 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	cmd(t_cmd_list *cmd_i, t_main *prmtrs)
{
	if (strcmp("cd", cmd_i->cmnd_words[0]) == 0)
		cmd_cd(cmd_i->cmnd_words, prmtrs->env_head, prmtrs);
	if (strcmp("echo", cmd_i->cmnd_words[0]) == 0)
		cmd_echo(cmd_i->cmnd_words, cmd_i->fd_out);
	if (strcmp("env", cmd_i->cmnd_words[0]) == 0)
		cmd_env(cmd_i->cmnd_words, prmtrs->env_head, cmd_i->fd_out, prmtrs);
	if (strcmp("exit", cmd_i->cmnd_words[0]) == 0)
		cmd_exit(cmd_i->cmnd_words, prmtrs);
	if (strcmp("export", cmd_i->cmnd_words[0]) == 0)
		cmd_export(cmd_i->cmnd_words, &prmtrs->env_head, cmd_i->fd_out);
	if (strcmp("pwd", cmd_i->cmnd_words[0]) == 0)
		cmd_pwd(cmd_i->fd_out, prmtrs);
	if (strcmp("unset", cmd_i->cmnd_words[0]) == 0)
		cmd_unset(cmd_i->cmnd_words, &prmtrs->env_head, prmtrs);
	return (0);
}
