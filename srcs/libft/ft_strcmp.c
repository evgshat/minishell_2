/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:01 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:02 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	while (*ptr_str1 != '\0' && *ptr_str2 != '\0')
	{
		if (*ptr_str1 != *ptr_str2)
			return (*ptr_str1 - *ptr_str2);
		ptr_str1++;
		ptr_str2++;
	}
	if (*ptr_str1 == '\0' && *ptr_str2 == '\0')
		return (0);
	else
		return (*ptr_str1 - *ptr_str2);
}
