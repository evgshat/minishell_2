/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_r_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:11 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:01:06 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	double_r_fd(t_cmd_list *tmp)
{
	tmp->fd_out = open(tmp->a_red,
			O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (tmp->fd_out < 0)
		return (NOT_EXECUTE);
	return (EXECUTE);
}
