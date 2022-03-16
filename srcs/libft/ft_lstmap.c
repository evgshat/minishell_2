/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:48 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:29:48 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_begin;
	t_list	*p;

	if (lst == NULL)
		return (NULL);
	new_begin = ft_lstnew(f(lst->content));
	if (new_begin == NULL)
	{
		return (NULL);
	}
	p = new_begin;
	lst = lst->next;
	while (lst != NULL)
	{
		p = ft_lstnew(f(lst->content));
		if (p == NULL)
		{
			ft_lstclear(&new_begin, del);
			return (NULL);
		}
		ft_lstadd_back(&new_begin, p);
		lst = lst->next;
	}
	return (new_begin);
}
