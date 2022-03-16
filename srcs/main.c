/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:39:12 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:28:18 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_structures.h"
#include "parsing.h"
#include "my_shell.h"
#include <stdio.h>

void	routine_parsing_executing(t_main *prmtrs)
{
	int		parinsg_validation_result;

	prmtrs->cmd_head = NULL;
	prmtrs->exit_status = 0;
	while (true)
	{
		parinsg_validation_result = parsing(prmtrs);
		if (parinsg_validation_result == NOT_EXECUTE)
			continue ;
		else if (parinsg_validation_result == EXECUTE)
			my_shell(prmtrs);
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{
	t_main	prmtrs;

	if (argc > 1)
		return (1);
	(void)argv;
	create_env_lst(&prmtrs, env);
	routine_parsing_executing(&prmtrs);
	return (0);
}
