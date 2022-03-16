/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:28 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:17:07 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		new_s[i] = '\0';
		i++;
	}
}
