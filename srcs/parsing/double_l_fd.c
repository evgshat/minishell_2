/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_l_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:37:01 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:00:50 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	double_l_fd(t_cmd_list *tmp)
{
	char	*line;
	int		fd;

	fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	line = readline("> ");
	while (ft_strcmp(line, tmp->a_red))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		ft_free_str(&line);
		line = readline("> ");
	}
	ft_free_str(&line);
	close(fd);
	tmp->fd_out = open(".tmp", O_RDONLY);
	return (EXECUTE);
}
