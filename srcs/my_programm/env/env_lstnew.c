/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:26 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:27 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

t_env_list	*env_lstnew(char **env_arr, int declare_flag)
{
	t_env_list	*p;

	p = (t_env_list *)malloc(1 * sizeof(t_env_list));
	if (p == NULL)
	{
		return (NULL);
	}
	p->env_arr = env_arr;
	p->declare_flag = declare_flag;
	p->next = NULL;
	return (p);
}
