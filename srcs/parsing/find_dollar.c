/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:33 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:00 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*find_dollar(t_cmd_list *tmp, int i, t_main *prmtrs)
{
	int		len;
	char	*str;
	char	*ex;

	i += 1;
	len = 0;
	if (tmp->orig_cmnd_str[i] == '?')
		return (ft_itoa(prmtrs->exit_status));
	while (tmp->orig_cmnd_str[i]
		&& !ft_isspace(tmp->orig_cmnd_str[i]) && tmp->orig_cmnd_str[i] != '"')
	{
		len += 1;
		i++;
	}
	str = ft_substr(tmp->orig_cmnd_str, (i - len), len);
	ex = str;
	str = getvalue_env_lst(str, prmtrs->env_head);
	ft_free_str(&ex);
	return (str);
}
