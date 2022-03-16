/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_red.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:00 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:08:15 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	b_red(int *j, t_cmd_list *tmp)
{
	while ((!ft_isalnum(tmp->orig_cmnd_str[(*j)])
			&& tmp->orig_cmnd_str[(*j)] != '\''
			&& tmp->orig_cmnd_str[(*j)] != '"'))
		(*j) -= 1;
	if (tmp->orig_cmnd_str[(*j)] && tmp->orig_cmnd_str[(*j)] == '\'')
	{
		if (b_quote(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	if (tmp->orig_cmnd_str[(*j)] && tmp->orig_cmnd_str[(*j)] == '"')
	{
		if (b_quotes(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	if (ft_isalnum(tmp->orig_cmnd_str[(*j)]))
	{
		if (b_alnum(j, tmp) == BREAK)
			return (BREAK);
		return (CONTINUE);
	}
	return (EXECUTE);
}
