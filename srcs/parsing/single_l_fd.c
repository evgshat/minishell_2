/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_l_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:43 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:01:49 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	single_l_fd(t_cmd_list *tmp)
{
	tmp->fd_in = open(tmp->a_red, O_RDONLY);
	if (tmp->fd_in < 0)
		return (NOT_EXECUTE);
	return (EXECUTE);
}
