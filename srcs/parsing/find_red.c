/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:37 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:05:03 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	right_red(t_cmd_list *tmp, int *i)
{
	if (tmp->orig_cmnd_str[(*i) + 1] == '>')
	{
		tmp->is_double_r = true;
		double_r_red(tmp, (*i));
		if (double_r_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 2;
	}
	else
	{
		tmp->is_single_r = true;
		single_r_red(tmp, (*i));
		if (single_r_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 1;
	}
	return (EXECUTE);
}

int	left_red(t_cmd_list *tmp, int *i)
{
	if (tmp->orig_cmnd_str[(*i) + 1] == '<')
	{
		tmp->is_double_r = true;
		double_l_red(tmp, (*i));
		if (double_l_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 2;
	}
	else
	{
		tmp->is_single_r = true;
		single_l_red(tmp, (*i));
		if (single_l_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 1;
	}
	return (EXECUTE);
}

int	find_red(t_cmd_list *tmp, int i)
{
	if (tmp->orig_cmnd_str[i] == '>')
	{
		if (right_red(tmp, &i) == -1)
			return (-1);
	}
	else if (tmp->orig_cmnd_str[i] == '<')
		if (left_red(tmp, &i) == -1)
			return (-1);
	return (i);
}
