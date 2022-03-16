/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_alnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:45 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:00:17 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	condition(int j, t_cmd_list *tmp)
{
	if (j > 0 && !ft_isspace(tmp->orig_cmnd_str[j - 1])
		&& tmp->orig_cmnd_str[j] != '>'
		&& tmp->orig_cmnd_str[j] != '<')
		return (CONTINUE);
	return (BREAK);
}

int	stop(char **str)
{
	ft_free_str(str);
	return (BREAK);
}

int	b_alnum(int *j, t_cmd_list *tmp)
{
	int		len;
	char	*str;
	char	*ex;

	len = 0;
	while (condition(*j, tmp) == CONTINUE)
	{
		(*j)--;
		len += 1;
	}
	len += 1;
	str = ft_substr(tmp->orig_cmnd_str, (*j), len);
	if (find_builtin(tmp, (*j)) == 1)
		return (stop(&str));
	else
	{
		ex = ft_strdup(tmp->b_red);
		ft_free_str(&tmp->b_red);
		tmp->b_red = ft_strjoin(ex, str);
		ft_free_str(&ex);
	}
	(*j) -= 1;
	ft_free_str(&str);
	return (CONTINUE);
}
