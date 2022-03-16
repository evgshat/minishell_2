/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:29 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:11:05 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ch_right(const char *line, int *i)
{
	int	j;

	if (line[(*i) + 1] == '<')
		return (NOT_EXECUTE);
	if (line[(*i) + 1] == '>')
	{
		(*i) += 1;
		if (line[(*i) + 1] == '<' || line[(*i) + 1] == '>')
			return (NOT_EXECUTE);
	}
	j = 1;
	while (ft_isspace(line[(*i) + j]))
		j += 1;
	if (!ft_isalnum(line[(*i) + j]))
		return (NOT_EXECUTE);
	return (EXECUTE);
}

int	ch_left(const char *line, int *i)
{
	int	j;

	if (line[(*i) + 1] == '>')
		return (NOT_EXECUTE);
	if (line[(*i) + 1] == '<')
	{
		(*i) += 1;
		if (line[(*i) + 1] == '>' || line[(*i) + 1] == '<')
			return (NOT_EXECUTE);
	}
	j = 1;
	while (ft_isspace(line[(*i) + j]))
		j += 1;
	if (!ft_isalnum(line[(*i) + j]))
		return (NOT_EXECUTE);
	return (EXECUTE);
}

int	ch_quotes(bool *s_closed, bool *d_closed, char c)
{
	if (c == '\'' && (*s_closed) == true)
	{
		if ((*s_closed) == true)
			(*s_closed) = false;
		else
			(*s_closed) = true;
		return (CONTINUE);
	}
	if (c == '"' && (*d_closed) == true)
	{
		if ((*d_closed) == true)
			(*d_closed) = false;
		else
			(*d_closed) = true;
		return (CONTINUE);
	}
	return (EXECUTE);
}

int	ch_red(char *line)
{
	int		i;
	int		len;
	bool	s_closed;
	bool	d_closed;

	i = -1;
	s_closed = true;
	d_closed = true;
	len = ft_strlen(line);
	if (line[len - 1] == '>' || line[len - 1] == '<')
		return (NOT_EXECUTE);
	while (line[++i])
	{
		if (ch_quotes(&s_closed, &d_closed, line[i]) == CONTINUE)
			continue ;
		if (line[i] == '>' && d_closed == true && s_closed == true)
			if (ch_right(line, &i) == NOT_EXECUTE)
				return (NOT_EXECUTE);
		if (line[i] == '<' && d_closed == true && s_closed == true)
			if (ch_left(line, &i) == NOT_EXECUTE)
				return (NOT_EXECUTE);
	}
	return (EXECUTE);
}
