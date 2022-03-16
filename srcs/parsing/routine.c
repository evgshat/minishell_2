/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:23 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:01:43 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	routine(t_cmd_list **tmp, int *i, int ind, t_main *prmtrs)
{
	if (serch(tmp, i, ind, prmtrs) == -2)
		return ((*i));
	else if ((*tmp)->orig_cmnd_str[(*i)] == '$')
	{
		(*i) = dollar(tmp, (*i), ind, prmtrs);
		if ((*i) == CONTINUE)
			return (CONTINUE);
	}
	else if ((*tmp)->orig_cmnd_str[(*i)] == '>'
		|| (*tmp)->orig_cmnd_str[(*i)] == '<')
	{
		(*i) = find_red((*tmp), (*i));
		if ((*i) == -1)
			return (NOT_EXECUTE);
		if (serch(tmp, i, ind, prmtrs) == -2)
			return ((*i));
	}
	return ((*i));
}
