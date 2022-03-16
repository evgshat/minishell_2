/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:27 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:44 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	serch(t_cmd_list **tmp, int *i, int ind, t_main *prmtrs)
{
	int	flag;

	flag = 0;
	(*i) = skip_space(tmp, (*i));
	if ((*tmp)->orig_cmnd_str[(*i)] == '\'')
	{
		(*i) = quote(tmp, (*i), ind);
		flag = -2;
	}
	else if ((*tmp)->orig_cmnd_str[(*i)] == '"')
	{
		(*i) = quotes(tmp, (*i), ind, prmtrs);
		flag = -2;
	}
	else if (ft_isascii((*tmp)->orig_cmnd_str[(*i)])
		&& (*tmp)->orig_cmnd_str[(*i)] != '<'
		&& (*tmp)->orig_cmnd_str[(*i)] != '>'
		&& (*tmp)->orig_cmnd_str[(*i)] != '$')
	{
		(*i) = al_num(tmp, (*i), ind);
		flag = -2;
	}
	return (flag);
}
