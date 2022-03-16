/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:50 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:02 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	be_quote(int *j, t_cmd_list *tmp)
{
	int		len;
	char	*str;

	len = 0;
	while (tmp->orig_cmnd_str[(*j) - 1]
		   && tmp->orig_cmnd_str[(*j) - 1] != '\'')
	{
		(*j)--;
		len += 1;
	}
	len += 1;
	str = ft_substr(tmp->orig_cmnd_str, (*j), len);
	if (find_builtin(tmp, (*j)) == 1)
	{
		ft_free_str(&str);
		return (BREAK);
	}
	else
	{
		tmp->before_redirect = ft_strjoin(tmp->before_redirect, str);
	}
	(*j) -= 2;
	ft_free_str(&str);
	return (CONTINUE);
}
