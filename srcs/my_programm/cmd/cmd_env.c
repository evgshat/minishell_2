/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:34:32 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:35:59 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

static int	print_errno_env(char *str, t_main *prmtrs, int rtrn_value);

int	cmd_env(char **cmnd_words, t_env_list *env_head, int fd_out,
															t_main *prmtrs)
{
	t_env_list	*tmp;

	if (cmnd_words[1] != NULL)
		return (print_errno_env(cmnd_words[1], prmtrs, ERROR));
	tmp = env_head;
	while (tmp != NULL)
	{
		if (tmp->declare_flag != 0)
		{
			ft_putstr_fd(tmp->env_arr[0], fd_out);
			ft_putstr_fd("=", fd_out);
			ft_putstr_fd(tmp->env_arr[1], fd_out);
			ft_putstr_fd("\n", fd_out);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	print_errno_env(char *str, t_main *prmtrs, int rtrn_value)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	prmtrs->exit_status = 1;
	return (rtrn_value);
}
