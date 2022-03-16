/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:00 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:01 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		start_index;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
	{
		i++;
	}
	start_index = i;
	while (s1[i] != '\0')
	{
		i++;
	}
	i--;
	while (ft_strchr(set, s1[i]) != NULL && i > start_index)
	{
		i--;
	}
	s = ft_substr(s1, start_index, i - start_index + 1);
	if (s == NULL)
		return (NULL);
	return (s);
}
