/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:29 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:24 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_right(const char *line, int *i)
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

int	check_left(const char *line, int *i)
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

int	check_quotes(bool *s_closed, bool *d_closed, char c)
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

int	check_redirect(char *line)
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
		if (check_quotes(&s_closed, &d_closed, line[i]) == CONTINUE)
			continue ;
		if (line[i] == '>' && d_closed == true && s_closed == true)
			if (check_right(line, &i) == NOT_EXECUTE)
				return (NOT_EXECUTE);
		if (line[i] == '<' && d_closed == true && s_closed == true)
			if (check_left(line, &i) == NOT_EXECUTE)
				return (NOT_EXECUTE);
	}
	return (EXECUTE);
}
