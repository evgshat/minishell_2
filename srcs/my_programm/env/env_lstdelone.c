/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:49 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:50 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	env_lstdelone(t_env_list *lst, void *(*del)(char ***arr))
{
	if ((*del) != NULL)
	{
		(*del)(&lst->env_arr);
	}
	free(lst);
}
