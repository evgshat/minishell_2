/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_of_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:56 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:18 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	str_quote(const char *line, int *i, int len)
{
	(*i) += 1;
	while (line[(*i)] && line[(*i)++] != '\'')
		len++;
	if (!line[(*i)] && line[(*i) - 1] != '\'')
	{
		return (-1);
	}
	return (len);
}

int	str_quotes(const char *line, int *i, int len)
{
	(*i) += 1;
	while (line[(*i)] && line[(*i)++] != '"')
		len++;
	if (!line[(*i)] && line[(*i) - 1] != '"')
	{
		return (-1);
	}
	return (len);
}

int	len_of_str(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i])
	{
		while (line[i] && (ft_isspace(line[i])
				|| line[i] == '>' || line[i] == '<'))
			i++;
		if (line[i] && line[i] == '\'')
			return (str_quote(line, &i, len));
		if (line[i] && line[i] == '"')
			return (str_quotes(line, &i, len));
		if (line[i] && ft_isascii(line[i]))
		{
			while (line[i] && !ft_isspace(line[i])
				&& line[i] != '<' && line[i] != '>')
			{
				len += 1;
				i++;
			}
			return (len);
		}
		i++;
	}
	return (0);
}
