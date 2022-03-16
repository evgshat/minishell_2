/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_red.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:04:38 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:08:05 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	a_red(int j, t_cmd_list *tmp)
{
	while (tmp->orig_cmnd_str[j] && ft_isspace(tmp->orig_cmnd_str[j]))
		j++;
	if (tmp->orig_cmnd_str[j] && tmp->orig_cmnd_str[j] == '\'')
		a_quote(j, tmp);
	else if (tmp->orig_cmnd_str[j] && tmp->orig_cmnd_str[j] == '"')
		a_quotes(j, tmp);
	else
		a_alnum(j, tmp);
	return (EXECUTE);
}
