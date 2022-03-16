/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:24 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:25 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t	src_len;

	if (dst == NULL || src == NULL)
	{
		return (0);
	}
	if (dst_len == 0)
	{
		return (ft_strlen(src));
	}
	src_len = ft_strlen(src);
	if (src_len < dst_len - 1)
	{
		ft_memcpy(dst, src, src_len + 1);
	}
	else if (dst_len != 0)
	{
		ft_memcpy(dst, src, dst_len - 1);
		dst[dst_len - 1] = '\0';
	}
	return (src_len);
}
