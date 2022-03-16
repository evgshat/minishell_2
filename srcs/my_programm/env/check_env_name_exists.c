/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_name_exists.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:21 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:22 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	check_env_name_exists(char *name, t_env_list *env_head)
{
	while (env_head != NULL)
	{
		if (strcmp(name, env_head->env_arr[0]) == 0)
			return (true);
		env_head = env_head->next;
	}
	return (false);
}
