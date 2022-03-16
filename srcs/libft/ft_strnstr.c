/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:52 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	s2_len;

	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char *)s1);
	while (*s1 != '\0' && size >= s2_len)
	{
		if (*s1 == *s2 && !ft_memcmp(s1, s2, s2_len))
		{
			return ((char *)s1);
		}
		s1++;
		size--;
	}
	return (NULL);
}
