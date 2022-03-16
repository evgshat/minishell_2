/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:22 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:16:25 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*new_d;
	unsigned char	*new_s;

	if (src == NULL && dst == NULL)
		return (0);
	i = 0;
	new_d = (unsigned char *)dst;
	new_s = (unsigned char *)src;
	while (i < n)
	{
		new_d[i] = new_s[i];
		i++;
	}
	return (new_d);
}
