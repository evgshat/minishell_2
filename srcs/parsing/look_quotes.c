/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:01 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:21 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	find_quotes(const char *line, int *i)
{
	while (line[++(*i)])
	{
		if (line[(*i)] == '"')
			return (true);
	}
	return (false);
}

bool	find_quote(const char *line, int *i)
{
	while (line[++(*i)])
	{
		if (line[(*i)] == '\'')
			return (true);
	}
	return (false);
}

int	look_quotes(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '"')
		{
			if (find_quotes(line, &i) == true)
				continue ;
			else
				return (NOT_EXECUTE);
		}
		if (line[i] == '\'')
		{
			if (find_quote(line, &i) == true)
				continue ;
			else
				return (NOT_EXECUTE);
		}
	}
	return (EXECUTE);
}
