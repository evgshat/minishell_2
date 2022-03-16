/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:47 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:47 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	while (size--)
	{
		if (*ptr_str1 != *ptr_str2)
		{
			return (*ptr_str1 - *ptr_str2);
		}
		if (*ptr_str1 == '\0' && *ptr_str2 == '\0')
		{
			return (*ptr_str1 - *ptr_str2);
		}
		ptr_str1++;
		ptr_str2++;
	}
	return (0);
}
