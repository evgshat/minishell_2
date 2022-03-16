/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:56 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:57 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int value)
{
	while (*str != '\0')
	{
		if (*str == (char)value)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char)value == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
