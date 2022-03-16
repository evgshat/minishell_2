/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_cmd_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:34:17 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:34:18 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	redirect_cmd_fd(t_cmd_list *cmd_i)
{
	if (cmd_i->is_double_l == true || cmd_i->is_single_l == true)
	{
		dup2(cmd_i->fd_in, 0);
		close(cmd_i->fd_in);
	}
	else if (cmd_i->is_double_r == true || cmd_i->is_single_r == true)
	{
		dup2(cmd_i->fd_out, 1);
		close(cmd_i->fd_out);
	}
	else
	{
		dup2(cmd_i->fd_out, 1);
		dup2(cmd_i->fd_in, 0);
	}
	return (0);
}
