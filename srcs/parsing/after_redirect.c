/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:35 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:21:49 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	after_redirect(int j, t_cmd_list *tmp)
{
	while (tmp->orig_cmnd_str[j] && ft_isspace(tmp->orig_cmnd_str[j]))
		j++;
	if (tmp->orig_cmnd_str[j] && tmp->orig_cmnd_str[j] == '\'')
		af_quote(j, tmp);
	else if (tmp->orig_cmnd_str[j] && tmp->orig_cmnd_str[j] == '"')
		af_quotes(j, tmp);
	else
		af_alnum(j, tmp);
	return (EXECUTE);
}
