/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:42 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:31:43 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*new_s;
	int		i;

	if (s == NULL)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (new_s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i++] = '\0';
	return (new_s);
}
