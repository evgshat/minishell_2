/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:14 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:33 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	quote(t_cmd_list **tmp, int i, int ind)
{
	int	j;

	j = -1;
	i += 1;
	while ((*tmp)->orig_cmnd_str[i] != '\'')
		(*tmp)->cmnd_words[ind][++j] = (*tmp)->orig_cmnd_str[i++];
	i += 1;
	return (i);
}
