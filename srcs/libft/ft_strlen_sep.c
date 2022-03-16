/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:29 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:33 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_sep(const char *str, int value)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0' && *str != value)
	{
		i = i + 1;
		str++;
	}
	return (i);
}
