/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:05 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:20:53 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*new_s;
	size_t			i;
	unsigned char	ch;

	new_s = (unsigned char *)buf;
	i = 0;
	ch = (unsigned char)c;
	while (i < count)
	{
		if (*new_s == ch)
		{
			return (new_s);
		}
		new_s++;
		i++;
	}
	return (0);
}
