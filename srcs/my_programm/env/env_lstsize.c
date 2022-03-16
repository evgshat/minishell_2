/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:31 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:31 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	env_lstsize(t_env_list *lst)
{
	int			count;
	t_env_list	*p;

	p = lst;
	count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return (count);
}
