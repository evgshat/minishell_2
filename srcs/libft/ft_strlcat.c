/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:20 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:21 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	copy_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	else
	{
		dst += dst_len;
		dstsize -= dst_len;
		if (src_len >= dstsize)
		{
			copy_len = dstsize - 1;
		}
		else
		{
			copy_len = src_len;
		}
		ft_memcpy(dst, src, copy_len);
		*(dst + copy_len) = '\0';
		return (dst_len + src_len);
	}
}
