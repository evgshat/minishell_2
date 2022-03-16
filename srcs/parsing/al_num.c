/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:21:54 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	al_num(t_cmd_list **tmp, int i, int ind)
{
	int	j;

	j = -1;
	find_builtin((*tmp), i);
	while ((*tmp)->orig_cmnd_str[i] && !ft_isspace((*tmp)->orig_cmnd_str[i]))
		(*tmp)->cmnd_words[ind][++j] = (*tmp)->orig_cmnd_str[i++];
	return (i);
}
