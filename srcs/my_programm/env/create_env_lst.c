/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:26 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:16:30 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"
#include "libft.h"
#include "printf.h"

void	env_shlvl(t_main *prmtrs)
{
	t_env_list	*tmp;
	int			nb_shlvl;
	char		*str_shlvlv;
	char		*final_str;
	char		**cmnd_words;

	tmp = prmtrs->env_head;
	while (tmp != NULL)
	{
		if (strcmp("SHLVL", tmp->env_arr[0]) == 0)
		{
			if (tmp->env_arr[1] != NULL)
				nb_shlvl = ft_atoi(tmp->env_arr[1]) + 1;
			else
				nb_shlvl = 1;
		}
		tmp = tmp->next;
	}
	str_shlvlv = ft_itoa(nb_shlvl);
	final_str = ft_strjoin("export SHLVL=", str_shlvlv);
	cmnd_words = ft_split(final_str, ' ');
	cmd_export(cmnd_words, &prmtrs->env_head, STDOUT);
	ft_free_str(&str_shlvlv);
	ft_free_str(&final_str);
	ft_free_str_arr(&cmnd_words);
}

void	create_env_lst(t_main *prmtrs, char **env)
{
	int	i;

	i = 0;
	prmtrs->env_head = NULL;
	while (env[i] != NULL)
	{
		env_lstadd_back(&prmtrs->env_head, env_lstnew(env_split(env[i]), 1));
		i++;
	}
	env_shlvl(prmtrs);
}
