/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:26 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:29:27 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*buf;

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
