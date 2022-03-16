/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstsort_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:36 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:37 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	swap(t_env_list *a, t_env_list *b)
{
	int		tmp_declare_flag;
	char	**tmp_env_arr;

	tmp_declare_flag = a->declare_flag;
	a->declare_flag = b->declare_flag;
	b->declare_flag = tmp_declare_flag;
	tmp_env_arr = a->env_arr;
	a->env_arr = b->env_arr;
	b->env_arr = tmp_env_arr;
	return ;
}

int	do_while(t_env_list *env_head)
{
	int			swapped;
	t_env_list	*ptr1;
	t_env_list	*lptr;
	int			compare_res;

	lptr = NULL;
	swapped = 0;
	ptr1 = env_head;
	while (ptr1->next != lptr)
	{
		compare_res = ft_strcmp(ptr1->env_arr[0], ptr1->next->env_arr[0]);
		if (compare_res > 0)
		{
			swap(ptr1, ptr1->next);
			swapped = 1;
		}
		ptr1 = ptr1->next;
	}
	lptr = ptr1;
	return (swapped);
}

void	env_lstsort_bubble(t_env_list *env_head)
{
	int	swapped;

	if (env_head == NULL)
		return ;
	swapped = do_while(env_head);
	while (swapped)
		swapped = do_while(env_head);
	return ;
}
