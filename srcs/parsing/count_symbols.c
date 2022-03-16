/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:36 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:27 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_symbols(const char *line, char c)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (line[++i])
		if (line[i] == c)
			counter += 1;
	return (counter);
}
