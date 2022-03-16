/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:46 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:11 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	helper_1(int *exit_status)
{
	*exit_status = 127;
	return (NOT_EXECUTE);
}

int	handle_quotes(t_main *prmtrs)
{
	t_cmd_list	*tmp;
	int			arr_len;
	int			flag;
	int			i;
	int			ind;

	tmp = prmtrs->cmd_head;
	while (tmp)
	{
		i = 0;
		arr_len = len_of_array(tmp);
		tmp->cmnd_words = (char **)malloc(sizeof(char *) * (arr_len + 1));
		tmp->cmnd_words[arr_len] = NULL;
		ind = -1;
		while (tmp->orig_cmnd_str[i])
		{
			flag = make_str(tmp->orig_cmnd_str, i, &tmp, &ind);
			if (flag == -1)
				return (helper_1(&(prmtrs->exit_status)));
			if (flag == -2 || (routine(&tmp, &i, ind, prmtrs) == BREAK))
				break ;
		}
		tmp = tmp->next;
	}
	return (EXECUTE);
}
