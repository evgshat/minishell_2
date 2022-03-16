/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatevalue_env_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:50 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:51 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	update_if_value_exists(t_env_list *tmp, char *malloced_new_value)
{
	ft_free_str(&tmp->env_arr[1]);
	tmp->env_arr[1] = malloced_new_value;
	return ;
}

void	update_if_value_not_exists(t_env_list *tmp,
									char *malloced_new_value, char *name)
{
	char	**new_arr;

	ft_free_str_arr(&tmp->env_arr);
	new_arr = (char **)malloc(sizeof(char *) * 3);
	new_arr[0] = ft_strdup(name);
	new_arr[1] = malloced_new_value;
	new_arr[2] = NULL;
	tmp->env_arr = new_arr;
	return ;
}

void	updatevalue_env_lst(char *name,
								char *malloced_new_value, t_env_list **env_head)
{
	t_env_list	*tmp;

	tmp = *env_head;
	while (tmp != NULL)
	{
		if (strcmp(name, tmp->env_arr[0]) == 0)
		{
			if (tmp->env_arr[1] != NULL)
				update_if_value_exists(tmp, malloced_new_value);
			else
				update_if_value_not_exists(tmp, malloced_new_value, name);
		}
		tmp = tmp->next;
	}
	return ;
}
