/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_r_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:58 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:08:32 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	single_r_red(t_cmd_list *tmp, int i)
{
	int	j;

	j = i - 1;
	while (tmp->orig_cmnd_str[j])
		if (b_red(&j, tmp) == BREAK)
			break ;
	j = i + 1;
	a_red(j, tmp);
	return (EXECUTE);
}
