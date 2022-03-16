/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:31 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:32 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

static char	*create_line_from_nam_value(t_env_list *tmp)
{
	char	*result_1st_join;
	char	*result_2nd_join;

	if (ft_strlen(tmp->env_arr[1]) == 0)
		return (ft_strjoin(tmp->env_arr[0], "="));
	else
	{
		result_1st_join = ft_strjoin(tmp->env_arr[0], "=");
		result_2nd_join = ft_strjoin(result_1st_join, tmp->env_arr[1]);
		ft_free_str(&result_1st_join);
		return (result_2nd_join);
	}
}

static int	count_how_many_to_malloc(t_env_list *env_head)
{
	int	count;

	count = 0;
	while (env_head != NULL)
	{
		if (env_head->declare_flag == 1)
			count++;
		env_head = env_head->next;
	}
	return (count);
}

char	**env_create_arr(t_env_list *env_head)
{
	char		**env;
	t_env_list	*tmp;
	int			i;

	i = count_how_many_to_malloc(env_head);
	env = (char **)malloc(sizeof(char *) * (i + 1));
	env[i] = NULL;
	tmp = env_head;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->declare_flag == 0)
		{
			tmp = tmp->next;
			continue ;
		}
		env[i] = create_line_from_nam_value(tmp);
		i++;
		tmp = tmp->next;
	}
	return (env);
}
