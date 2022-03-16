/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:04 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:05 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*buf;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (substr == NULL)
	{
		return (NULL);
	}
	buf = substr;
	while (len-- && s[start] != '\0')
	{
		*substr = s[start++];
		substr++;
	}
	*substr = '\0';
	return (buf);
}
