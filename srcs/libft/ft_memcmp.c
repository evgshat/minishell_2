/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:09 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:18 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t size)
{
	unsigned char	*ptr_arr1;
	unsigned char	*ptr_arr2;

	ptr_arr1 = (unsigned char *)arr1;
	ptr_arr2 = (unsigned char *)arr2;
	if (ptr_arr1 == NULL || ptr_arr2 == NULL)
		return (-1);
	while (size--)
	{
		if (*ptr_arr1 != *ptr_arr2)
		{
			return (*ptr_arr1 - *ptr_arr2);
		}
		ptr_arr1++;
		ptr_arr2++;
	}
	return (0);
}
