/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_l_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:43 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:55 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	single_l_fd(t_cmd_list *tmp)
{
	tmp->fd_in = open(tmp->after_redirect, O_RDONLY);
	if (tmp->fd_in < 0)
		return (NOT_EXECUTE);
	return (EXECUTE);
}
