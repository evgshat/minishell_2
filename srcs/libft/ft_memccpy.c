/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:01 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:16:42 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char		*dest;
	unsigned char		*src;
	unsigned char		ch;
	size_t				i;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == ch)
		{
			dest[i] = src[i];
			i++;
			return (&dest[i]);
		}
		dest[i] = src[i];
		i++;
	}
	return (NULL);
}
