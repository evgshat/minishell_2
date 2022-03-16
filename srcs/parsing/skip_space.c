/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:39:03 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:24:10 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_space(t_cmd_list **tmp, int i)
{
	while ((*tmp)->orig_cmnd_str[i] && ft_isspace((*tmp)->orig_cmnd_str[i]))
		i++;
	return (i);
}
