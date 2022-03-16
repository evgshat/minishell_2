/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:56 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:17:04 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;
	char	ch;

	new_s = (char *)s;
	ch = (char)c;
	if (ch == '\0')
	{
		while (*new_s)
			new_s++;
		return (new_s);
	}
	while (*new_s)
	{
		if (*new_s == ch)
			return (new_s);
		new_s++;
	}
	return (NULL);
}
