/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:37 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:03 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	right_redir(t_cmd_list *tmp, int *i)
{
	if (tmp->orig_cmnd_str[(*i) + 1] == '>')
	{
		tmp->is_double_r = true;
		double_r_redirect(tmp, (*i));
		if (double_r_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 2;
	}
	else
	{
		tmp->is_single_r = true;
		single_r_redirect(tmp, (*i));
		if (single_r_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 1;
	}
	return (EXECUTE);
}

int	left_redir(t_cmd_list *tmp, int *i)
{
	if (tmp->orig_cmnd_str[(*i) + 1] == '<')
	{
		tmp->is_double_r = true;
		double_l_redirect(tmp, (*i));
		if (double_l_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 2;
	}
	else
	{
		tmp->is_single_r = true;
		single_l_redirect(tmp, (*i));
		if (single_l_fd(tmp) == NOT_EXECUTE)
			return (-1);
		(*i) += 1;
	}
	return (EXECUTE);
}

int	find_redirect(t_cmd_list *tmp, int i)
{
	if (tmp->orig_cmnd_str[i] == '>')
	{
		if (right_redir(tmp, &i) == -1)
			return (-1);
	}
	else if (tmp->orig_cmnd_str[i] == '<')
		if (left_redir(tmp, &i) == -1)
			return (-1);
	return (i);
}
