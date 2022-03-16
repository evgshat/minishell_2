/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_quotes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:22:30 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	b_quotes(int *j, t_cmd_list *tmp)
{
	int		len;
	char	*str;

	len = 0;
	while (tmp->orig_cmnd_str[(*j) - 1]
		&& tmp->orig_cmnd_str[(*j) - 1] != '"')
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
		tmp->b_red = ft_strjoin(tmp->b_red, str);
	}
	(*j) -= 2;
	ft_free_str(&str);
	return (CONTINUE);
}
