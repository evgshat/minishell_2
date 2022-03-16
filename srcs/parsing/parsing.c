/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:24:57 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:24:58 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(t_main *prmtrs)
{
	char	*line;

	setup_terminal();
	prmtrs->orig_line_input = readline("my_shell$ ");
	if (prmtrs->orig_line_input == NULL)
	{
		printf("my_shell$ exit\n");
		free_prmtrs(prmtrs, SUCCESSFUL_EXIT);
		exit(prmtrs->exit_status);
		return (NOT_EXECUTE);
	}
	line = ft_strdup(prmtrs->orig_line_input);
	if (ft_strlen(prmtrs->orig_line_input) == 0)
	{
		ft_free_str(&(prmtrs->orig_line_input));
		ft_free_str(&line);
		return (NOT_EXECUTE);
	}
	add_history(prmtrs->orig_line_input);
	if (check_input(line, prmtrs) == NOT_EXECUTE)
	{
		ft_free_str(&(prmtrs->orig_line_input));
		return (NOT_EXECUTE);
	}
	return (EXECUTE);
}
