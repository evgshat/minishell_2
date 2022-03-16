/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:05 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:25 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	make_str(char *line, int i, t_cmd_list **tmp, int *ind)
{
	int	len;

	len = len_of_str(line, i);
	if (len == -1)
		return (-1);
	if (len == 0)
		return (-2);
	(*tmp)->cmnd_words[++(*ind)] = (char *)malloc(sizeof(char) * (len + 1));
	(*tmp)->cmnd_words[(*ind)][len] = '\0';
	return (EXECUTE);
}
