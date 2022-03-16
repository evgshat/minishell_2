/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_alnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:44:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:59:20 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	a_alnum(int j, t_cmd_list *tmp)
{
	int		len;
	char	*ex;

	len = 0;
	while (tmp->orig_cmnd_str[j])
	{
		if (ft_isspace(tmp->orig_cmnd_str[j])
			|| tmp->orig_cmnd_str[j] == '>' || tmp->orig_cmnd_str[j] == '<')
			break ;
		len += 1;
		j++;
	}
	if (tmp->a_red != NULL)
	{
		ex = ft_strdup(tmp->a_red);
		ft_free_str(&(tmp->a_red));
		tmp->a_red = ft_substr(tmp->orig_cmnd_str, (j - len), j);
		ft_free_str(&ex);
	}
	else
		tmp->a_red = ft_substr(tmp->orig_cmnd_str, (j - len), j);
}
