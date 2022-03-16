/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:05 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:06 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int value, size_t size)
{
	unsigned char	*ptr_arr;

	ptr_arr = (unsigned char *)arr;
	while (size--)
	{
		if (*ptr_arr != (unsigned char)value)
		{
			ptr_arr++;
		}
		else
		{
			return (ptr_arr);
		}
	}
	return (NULL);
}
