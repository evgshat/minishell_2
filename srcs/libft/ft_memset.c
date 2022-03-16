/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:30 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:31 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int value, size_t size)
{
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	while (size != 0)
	{
		*ptr_dst = (unsigned char)value;
		size = size - 1;
		ptr_dst++;
	}
	return (dst);
}
