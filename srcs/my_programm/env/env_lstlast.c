/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:13 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:14 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

t_env_list	*env_lstlast(t_env_list *lst)
{
	t_env_list	*p;

	if (lst == NULL)
	{
		return (NULL);
	}
	p = lst;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return (p);
}
