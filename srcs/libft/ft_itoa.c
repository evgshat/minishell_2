/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:15 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:29:16 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		len;
	long int	ln;

	ln = n;
	if (n >= 0)
		len = ft_nbrlen(n);
	else
		len = ft_nbrlen(n) + 1;
	s = (char *)ft_calloc(len + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		ln = (-1) * ln;
	}
	while (len-- > 0 && s[len] != '-')
	{
		s[len] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (s);
}
