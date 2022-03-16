/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:27:17 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:27:19 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define ERROR -1

int			get_next_line(int fd, char **line);
int			gnl_check_or_creat_buf(int fd, char **buf);
int			gnl_read_line(int fd, char **buf, char **line);
char		*ft_leftjoin_sep(char *s1, char *s2, int value);
char		*ft_rewrite_str(char *s, int value);

#endif
