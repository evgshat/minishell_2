/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:11 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:12 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		s1_len;
	char		*s_copy;

	s1_len = ft_strlen(s1);
	s_copy = malloc(s1_len * sizeof(char) + 1);
	if (s_copy == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s_copy, s1, s1_len);
	*(s_copy + s1_len) = '\0';
	return (s_copy);
}
