/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:13 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:17 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_line(char *line)
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
