/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   af_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:20 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:21:36 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	af_alnum(int j, t_cmd_list *tmp)
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
	if (tmp->after_redirect != NULL)
	{
		ex = ft_strdup(tmp->after_redirect);
		ft_free_str(&(tmp->after_redirect));
		tmp->after_redirect = ft_substr(tmp->orig_cmnd_str, (j - len), j);
		ft_free_str(&ex);
	}
	else
		tmp->after_redirect = ft_substr(tmp->orig_cmnd_str, (j - len), j);
}
