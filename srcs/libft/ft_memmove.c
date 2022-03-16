/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:26 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:22:13 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_d;
	unsigned char	*new_s;
	size_t			n;

	new_d = (unsigned char *)dst;
	new_s = (unsigned char *)src;
	n = len;
	if (new_d < new_s)
		ft_memcpy(new_d, new_s, len);
	else if (new_d > new_s)
	{
		while (len-- > 1)
		{
			new_d++;
			new_s++;
		}
		while (n-- > 0)
			*(new_d--) = *(new_s--);
		new_d = (unsigned char *)dst;
	}
	return (new_d);
}
