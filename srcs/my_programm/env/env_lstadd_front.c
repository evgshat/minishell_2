/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:41 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstadd_front(t_env_list **lst, t_env_list *new)
{
	t_env_list	*buf;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else if (new == NULL)
	{
		return ;
	}
	else
	{
		buf = *lst;
		*lst = new;
		new->next = buf;
	}
}
