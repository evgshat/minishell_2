/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalue_env_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:45 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:46 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

char	*getvalue_env_lst(char *name, t_env_list *env_head)
{
	t_env_list	*tmp;

	tmp = env_head;
	while (tmp != NULL)
	{
		if (ft_strcmp(name, tmp->env_arr[0]) == 0)
		{
			if (tmp->env_arr[1] != NULL)
				return (ft_strdup(tmp->env_arr[1]));
		}
		tmp = tmp->next;
	}
	return (NULL);
}
