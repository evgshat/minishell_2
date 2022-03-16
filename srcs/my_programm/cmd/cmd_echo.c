/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:47:29 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:10:06 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

static int	ch_n_flag(char *str, int *flag);

int	cmd_echo(char **cmnd_words, int fd_out)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (cmnd_words[i] != NULL && ch_n_flag(cmnd_words[i], &flag) == true)
		i++;
	while (cmnd_words[i] != NULL)
	{
		ft_putstr_fd(cmnd_words[i], fd_out);
		if (cmnd_words[++i] != NULL)
			ft_putstr_fd(" ", fd_out);
	}
	if (flag != 1)
		ft_putstr_fd("\n", fd_out);
	return (0);
}

static int	ch_n_flag(char *str, int *flag)
{
	if (*str++ == '-')
	{
		if (*str == 'n')
		{
			while (*str != '\0')
			{
				if (*str != 'n')
					return (false);
				str++;
			}
			*flag = 1;
			return (true);
		}
	}
	return (false);
}
