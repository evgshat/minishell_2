/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:15:45 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:19:04 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	print_export_declare_x(t_env_list *env_head, int fd_out)
{
	t_env_list	*tmp;

	env_lstsort_bubble(env_head);
	tmp = env_head;
	while (tmp != NULL)
	{
		ft_putstr_fd("declare -x ", fd_out);
		ft_putstr_fd(tmp->env_arr[0], fd_out);
		if (tmp->env_arr[1] == NULL)
			ft_putstr_fd("\n", fd_out);
		else
		{
			ft_putstr_fd("=\"", fd_out);
			ft_putstr_fd(tmp->env_arr[1], fd_out);
			ft_putstr_fd("\"\n", fd_out);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	cmd_export(char **cmnd_words, t_env_list **env_head, int fd_out)
{
	char	**arr;
	int		i;
	char	*name;

	if (cmnd_words[1] == NULL)
		return (print_export_declare_x(*env_head, fd_out));
	else
	{
		i = 1;
		while (cmnd_words[i] != NULL)
		{
			name = ft_strdup_sep(cmnd_words[i], '=');
			if (ch_env_name_exists(name, *env_head) == true)
				unset_delete_lst_element(name, env_head);
			ft_free_str(&name);
			arr = env_split(cmnd_words[i]);
			if (arr[1] == NULL)
				env_lstadd_back(env_head, env_lstnew(arr, 0));
			else
				env_lstadd_back(env_head, env_lstnew(arr, 1));
			i++;
		}
	}
	return (0);
}
