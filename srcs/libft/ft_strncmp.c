/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:47 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:26:52 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			i;

	i = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (new_s1[i] != '\0') && (new_s2[i] != '\0')
		&& (new_s1[i] == new_s2[i]))
		i++;
	return (new_s1[i] - new_s2[i]);
}
