/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:19 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:37 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	call_dollar_helper(char **str)
{
	ft_free_str(str);
	return (BREAK);
}

int	call_dollar_helper_2(char *dol_str, t_cmd_list **tmp, int ind)
{
	char	*ex;

	ex = (*tmp)->cmnd_words[ind];
	(*tmp)->cmnd_words[ind] = ft_strdup(dol_str);
	ft_free_str(&ex);
	return (EXECUTE);
}

int	call_dollar(t_cmd_list **tmp, int (*i), int ind, t_main *prmtrs)
{
	char	*dol_str;
	char	*ex;

	if (!ft_isspace((*tmp)->orig_cmnd_str[(*i) + 1]))
	{
		dol_str = find_dollar((*tmp), (*i), prmtrs);
		if (dol_str)
			call_dollar_helper_2(dol_str, tmp, ind);
		while ((*tmp)->orig_cmnd_str[++(*i)])
			if (!ft_isalnum((*tmp)->orig_cmnd_str[(*i)])
				&& (*tmp)->orig_cmnd_str[(*i)] != '?')
				return (call_dollar_helper(&dol_str));
	}
	else
	{
		ex = (*tmp)->cmnd_words[ind];
		(*tmp)->cmnd_words[ind] = ft_strdup("$");
		ft_free_str(&ex);
		(*i) += 1;
	}
	ft_free_str(&dol_str);
	return (*i);
}

int	quotes(t_cmd_list **tmp, int i, int ind, t_main *prmtrs)
{
	int	j;

	j = -1;
	i += 1;
	while ((*tmp)->orig_cmnd_str[i] != '"')
	{
		if ((*tmp)->orig_cmnd_str[i] != '$')
			(*tmp)->cmnd_words[ind][++j] = (*tmp)->orig_cmnd_str[i++];
		else
			call_dollar(tmp, &i, ind, prmtrs);
	}
	i += 1;
	return (i);
}
