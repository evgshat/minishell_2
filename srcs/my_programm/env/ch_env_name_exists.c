/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_env_name_exists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:21 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:12:55 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	ch_env_name_exists(char *name, t_env_list *env_head)
{
	while (env_head != NULL)
	{
		if (strcmp(name, env_head->env_arr[0]) == 0)
			return (true);
		env_head = env_head->next;
	}
	return (false);
}
