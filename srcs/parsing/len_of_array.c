/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_of_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:14 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	len_alnum(const t_cmd_list *tmp, int *i, int *count)
{
	while (tmp->orig_cmnd_str[(*i)])
	{
		if (!tmp->orig_cmnd_str[(*i)] || ft_isspace(tmp->orig_cmnd_str[(*i)])
			|| tmp->orig_cmnd_str[(*i)] == '>'
			|| tmp->orig_cmnd_str[(*i)] == '<')
		{
			(*i) += 1;
			(*count) += 1;
			break ;
		}
		(*i)++;
	}
	if (!tmp->orig_cmnd_str[(*i)] && ft_isascii(tmp->orig_cmnd_str[(*i) - 1])
		&& !ft_isspace(tmp->orig_cmnd_str[(*i)])
		&& tmp->orig_cmnd_str[(*i)] != '<' && tmp->orig_cmnd_str[(*i)] != '>')
	{
		(*count) += 1;
		return (BREAK);
	}
	return (EXECUTE);
}

int	len_quote(const t_cmd_list *tmp, int *i, int *count)
{
	bool	s_closed;

	s_closed = false;
	(*i) += 1;
	while (tmp->orig_cmnd_str[(*i)] && s_closed == false)
	{
		if (tmp->orig_cmnd_str[(*i)] == '\'')
		{
			(*i) += 1;
			(*count) += 1;
			s_closed = true;
			break ;
		}
		(*i)++;
	}
	return (EXECUTE);
}

int	len_quotes(const t_cmd_list *tmp, int *i, int *count)
{
	bool	d_closed;

	d_closed = false;
	(*i) += 1;
	while (tmp->orig_cmnd_str[(*i)] && d_closed == false)
	{
		if (tmp->orig_cmnd_str[(*i)] == '"')
		{
			(*i) += 1;
			(*count) += 1;
			d_closed = true;
			break ;
		}
		(*i)++;
	}
	return (EXECUTE);
}

int	len_of_array(const t_cmd_list *tmp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tmp->orig_cmnd_str[i])
	{
		while (ft_isspace(tmp->orig_cmnd_str[i])
			|| tmp->orig_cmnd_str[i] == '>' || tmp->orig_cmnd_str[i] == '<')
			i++;
		if (tmp->orig_cmnd_str[i] && tmp->orig_cmnd_str[i] == '\'')
			len_quote(tmp, &i, &count);
		else if (tmp->orig_cmnd_str[i] && tmp->orig_cmnd_str[i] == '"')
			len_quotes(tmp, &i, &count);
		else if (ft_isascii(tmp->orig_cmnd_str[i]))
		{
			if (len_alnum(tmp, &i, &count) == BREAK)
				break ;
		}
	}
	return (count);
}
