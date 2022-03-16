/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:38 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	stop_it(char **str, int i)
{
	ft_free_str(str);
	return (i);
}

int	dollar_helper(char *dol_str, t_cmd_list **tmp, int ind)
{
	char	*ex;

	ex = (*tmp)->cmnd_words[ind];
	(*tmp)->cmnd_words[ind] = ft_strdup(dol_str);
	ft_free_str(&ex);
	return (EXECUTE);
}

int	dollar(t_cmd_list **tmp, int i, int ind, t_main *prmtrs)
{
	char	*dol_str;
	char	*ex;

	if (!ft_isspace((*tmp)->orig_cmnd_str[i + 1]))
	{
		dol_str = find_dollar((*tmp), i, prmtrs);
		if (dol_str)
			dollar_helper(dol_str, tmp, ind);
		while ((*tmp)->orig_cmnd_str[++i])
			if (!ft_isalnum((*tmp)->orig_cmnd_str[i])
				&& (*tmp)->orig_cmnd_str[i] != '?')
				return (stop_it(&dol_str, i));
	}
	else
	{
		ex = (*tmp)->cmnd_words[ind];
		(*tmp)->cmnd_words[ind] = ft_strdup("$");
		ft_free_str(&ex);
		i += 1;
	}
	ft_free_str(&dol_str);
	return (i);
}
