/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_r_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:58 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:24:06 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	single_r_redirect(t_cmd_list *tmp, int i)
{
	int	j;

	j = i - 1;
	while (tmp->orig_cmnd_str[j])
		if (before_redirect(&j, tmp) == BREAK)
			break ;
	j = i + 1;
	after_redirect(j, tmp);
	return (EXECUTE);
}
