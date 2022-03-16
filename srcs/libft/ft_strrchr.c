/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:56 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int value)
{
	int		len;
	int		i;
	char	*buf;

	len = ft_strlen(str);
	buf = NULL;
	i = 0;
	while (i < len)
	{
		if (*str == (char)value)
		{
			buf = (char *)str;
		}
		str++;
		i++;
	}
	if ((char)value == '\0')
	{
		return ((char *)str);
	}
	return (buf);
}
