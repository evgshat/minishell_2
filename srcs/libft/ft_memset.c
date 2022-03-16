/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:30 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:16:12 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_s;
	char			s;

	i = 0;
	s = 0;
	new_s = (unsigned char *)b;
	s = (unsigned char)c;
	while (i < n)
	{
		new_s[i] = c;
		i++;
	}
	return (new_s);
}
