/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:26 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:27 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (src == NULL && dst == NULL)
	{
		return (NULL);
	}
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst < ptr_src)
	{
		while (size--)
		{
			*ptr_dst++ = *ptr_src++;
		}
	}
	if (ptr_dst >= ptr_src)
	{
		while (size--)
		{
			ptr_dst[size] = ptr_src[size];
		}
	}
	return (dst);
}
