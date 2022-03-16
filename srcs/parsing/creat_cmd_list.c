/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:41 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:31 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_count_sep(char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

t_cmd_list	*cmd_list_new(char *orig_cmnd_str)
{
	t_cmd_list	*p;

	p = (t_cmd_list *)malloc(1 * sizeof(t_cmd_list));
	if (p == NULL)
		return (NULL);
	p->orig_cmnd_str = orig_cmnd_str;
	p->copy_cmnd_str = NULL;
	p->before_redirect = NULL;
	p->after_redirect = NULL;
	p->cmnd_words = NULL;
	p->is_builtin = false;
	p->is_double_r = false;
	p->is_double_l = false;
	p->is_single_r = false;
	p->is_single_l = false;
	p->is_pipe = false;
	p->fd_in = STDIN;
	p->fd_out = STDOUT;
	p->next = NULL;
	return (p);
}

void	cmd_list_add_back(t_cmd_list **lst, t_cmd_list *new)
{
	t_cmd_list	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new;
}

int	put_pipe_flag(t_cmd_list *cmd_head)
{
	t_cmd_list	*cmd_i;
	int			count;

	cmd_i = cmd_head;
	count = 1;
	while (cmd_i->next != NULL)
	{
		count++;
		cmd_i = cmd_i->next;
	}
	while (count > 1)
	{
		cmd_head->is_pipe = true;
		cmd_head = cmd_head->next;
		count--;
	}
	return (0);
}

int	creat_cmd_list(t_main *prmtrs)
{
	char	**str_arr;
	int		i;

	prmtrs->nb_pipes = ft_count_sep(prmtrs->orig_line_input, '|');
	str_arr = ft_split(prmtrs->orig_line_input, '|');
	i = 0;
	while (str_arr[i] != NULL)
	{
		cmd_list_add_back(&prmtrs->cmd_head,
			cmd_list_new(ft_strdup(str_arr[i])));
		i++;
	}
	ft_free_str_arr(&str_arr);
	put_pipe_flag(prmtrs->cmd_head);
	return (0);
}
