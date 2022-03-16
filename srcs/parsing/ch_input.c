/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:05 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:56:35 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	del_lst_wrd(t_main *prmtrs)
{
	int			i;
	t_cmd_list	*tmp;

	tmp = prmtrs->cmd_head;
	while (tmp)
	{
		i = 0;
		if (tmp->is_double_l == true || tmp->is_double_r == true
			|| tmp->is_single_l == true || tmp->is_single_r == true)
		{
			while (tmp->cmnd_words[i + 1])
				i++;
			ft_free_str(&(tmp->cmnd_words[i]));
		}
		tmp = tmp->next;
	}
	return (EXECUTE);
}

int	helper_3(t_main *prmtrs)
{
	ft_free_str(&prmtrs->copy_line_input);
	return (NOT_EXECUTE);
}

int	ch_input(char *line, t_main *prmtrs)
{
	prmtrs->copy_line_input = line;
	if (ch_line(line) == NOT_EXECUTE)
		return (helper_3(prmtrs));
	if (ch_pipe(prmtrs, prmtrs->copy_line_input)
		== NOT_EXECUTE || ch_red(prmtrs->copy_line_input)
		== NOT_EXECUTE || look_quotes(prmtrs->copy_line_input)
		== NOT_EXECUTE)
	{
		prmtrs->exit_status = 258;
		printf("my_shell: syntax error near unexpected token\n");
		ft_free_str(&prmtrs->copy_line_input);
		return (NOT_EXECUTE);
	}
	creat_cmd_list(prmtrs);
	if (handle_quotes(prmtrs) == NOT_EXECUTE)
	{
		prmtrs->exit_status = 1;
		free_prmtrs(prmtrs, DONT_CLEAN_ENV);
		return (NOT_EXECUTE);
	}
	del_lst_wrd(prmtrs);
	ft_free_str(&prmtrs->orig_line_input);
	return (EXECUTE);
}
