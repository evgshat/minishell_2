/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_r_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:53 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:24:02 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	single_r_fd(t_cmd_list *tmp)
{
	tmp->fd_out = open(tmp->after_redirect, O_CREAT
			| O_WRONLY | O_TRUNC, S_IRWXU);
	if (tmp->fd_out < 0)
		return (NOT_EXECUTE);
	return (EXECUTE);
}
