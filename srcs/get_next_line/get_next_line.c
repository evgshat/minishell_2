/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:12 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:09:53 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		*buf[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (ERROR);
	if (gnl_ch_or_creat_buf(fd, buf) == ERROR)
		return (ERROR);
	*line = NULL;
	return (gnl_read_line(fd, buf, line));
}

int	gnl_ch_or_creat_buf(int fd, char **buf)
{
	if (buf[fd] == NULL)
	{
		buf[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf[fd] == NULL)
		{
			return (ERROR);
		}
		buf[fd][0] = '\0';
	}
	return (true);
}

int	gnl_read_line(int fd, char **buf, char **line)
{
	long long	bytes_rd;

	*line = ft_leftjoin_sep(*line, buf[fd], '\n');
	if (*line == NULL)
		return (ft_free_str(&(buf[fd])) - 1);
	while (ft_strchr(buf[fd], '\n') == NULL)
	{
		bytes_rd = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_rd == 0 || bytes_rd == -1)
		{
			ft_free_str(&(buf[fd]));
			return ((int)bytes_rd);
		}
		buf[fd][bytes_rd] = '\0';
		*line = ft_leftjoin_sep(*line, buf[fd], '\n');
		if (*line == NULL)
			return (ft_free_str(&(buf[fd])) - 1);
	}
	buf[fd] = ft_rewrite_str(buf[fd], '\n');
	if (buf[fd] == NULL)
		return (ft_free_str(&(buf[fd])) - 1);
	return (1);
}
