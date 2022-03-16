/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:00 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:09 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	before_redirect(int *j, t_cmd_list *tmp)
{
	while ((!ft_isalnum(tmp->orig_cmnd_str[(*j)])
			&& tmp->orig_cmnd_str[(*j)] != '\''
			&& tmp->orig_cmnd_str[(*j)] != '"'))
		(*j) -= 1;
	if (tmp->orig_cmnd_str[(*j)] && tmp->orig_cmnd_str[(*j)] == '\'')
	{
		if (be_quote(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	if (tmp->orig_cmnd_str[(*j)] && tmp->orig_cmnd_str[(*j)] == '"')
	{
		if (be_quotes(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	if (ft_isalnum(tmp->orig_cmnd_str[(*j)]))
	{
		if (be_alnum(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	return (EXECUTE);
}
