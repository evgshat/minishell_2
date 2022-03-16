/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:44 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:45 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstclear(t_env_list **lst, void *(*del)(char ***arr))
{
	if (*lst && lst)
	{
		env_lstclear(&(*lst)->next, del);
		env_lstdelone(*lst, del);
		*lst = NULL;
	}
}
