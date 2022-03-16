/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:03 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstiter(t_env_list *lst, void (*f)(void *))
{
	t_env_list	*p;

	p = lst;
	if (f != NULL)
	{
		while (p != NULL)
		{
			f(p->env_arr);
			p = p->next;
		}
	}
}
