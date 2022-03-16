/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:13 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:55:18 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ch_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_isascii(line[i]) && !ft_isspace(line[i]))
			return (EXECUTE);
	}
	return (NOT_EXECUTE);
}
