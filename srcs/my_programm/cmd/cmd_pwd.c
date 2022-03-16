/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:14:44 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:14:53 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

int	cmd_pwd(int fd_out, t_main *prmtrs)
{
	char	*pwd_str;

	pwd_str = getcwd(NULL, 0);
	if (pwd_str == NULL)
	{
		ft_putstr_fd("error retrieving current directory: getcwd: cannot \
				access parent directories: No such file or directory", 2);
		ft_putendl_fd(strerror(errno), 2);
		prmtrs->exit_status = 1;
		return (ERROR);
	}
	ft_putendl_fd(pwd_str, fd_out);
	free(pwd_str);
	return (0);
}
