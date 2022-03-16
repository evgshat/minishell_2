/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:22 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:23 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char		*ptr_dst;
	const char	*ptr_src;

	if (src == NULL && dst == NULL)
	{
		return (NULL);
	}
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	while (size != 0)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		size--;
	}
	return (dst);
}
