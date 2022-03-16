/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:21 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:20 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	counter(char *line, int *i, t_main *prmtrs)
{
	int	j;

	if (line[(*i) + 1] == '|' && line[(*i) + 2] == '|')
		return (NOT_EXECUTE);
	while (line[(*i)] == '|')
		(*i)++;
	j = 1;
	while (ft_isspace(line[(*i) + j]))
		j++;
	if (!ft_isalpha(line[(*i) + j]))
		return (NOT_EXECUTE);
	j = (*i);
	while (line[++j])
		if (ft_isalpha(line[j]))
			break ;
	if (line[j] == '\0')
		return (NOT_EXECUTE);
	prmtrs->nb_pipes += 1;
	return (EXECUTE);
}

int	change_flags(int *s_flag, int *d_flag, const char *line, int i)
{
	if (line[i] == '\'' && (*s_flag) == 0)
		(*s_flag) = 1;
	else if (line[i] == '"' && (*s_flag) == 1)
		(*s_flag) = 0;
	if (line[i] == '"' && (*d_flag) == 0)
		(*d_flag) = 1;
	else if (line[i] == '"' && (*d_flag) == 1)
		(*d_flag) = 0;
	return (EXECUTE);
}

int	check_pipe(t_main *prmtrs, char *line)
{
	int	i;
	int	s_flag;
	int	d_flag;
	int	len;

	i = -1;
	s_flag = 0;
	d_flag = 0;
	len = ft_strlen(line);
	if (line[i + 1] == '|' || line[len - 1] == '|')
		return (NOT_EXECUTE);
	while (line[++i])
	{
		if (!ft_isascii(line[i]))
			return (NOT_EXECUTE);
		change_flags(&s_flag, &d_flag, line, i);
		if (line[i] == '|' && s_flag == 0 && d_flag == 0)
			if (counter(line, &i, prmtrs) == NOT_EXECUTE)
				return (NOT_EXECUTE);
	}
	return (EXECUTE);
}
