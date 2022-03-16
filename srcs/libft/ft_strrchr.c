/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:27:29 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new_s;
	char	*a;
	char	ch;

	new_s = (char *)s;
	a = (char *)s;
	ch = (char)c;
	if (ch == '\0')
	{
		while (*new_s)
			new_s++;
		return (new_s);
	}
	while (*new_s != '\0')
		new_s++;
	new_s--;
	while (new_s >= a)
	{
		if (*new_s == ch)
			return (new_s);
		new_s--;
	}
	return (0);
}
