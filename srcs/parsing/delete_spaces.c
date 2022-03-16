/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:47 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:34 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*delete_spaces(char *str)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str)
	{
		i = -1;
		j = -1;
		while (str[++i])
			if (ft_isalpha(str[i]))
				ret[++j] = str[i];
		ret[++j] = '\0';
	}
	ft_free_str(&str);
	return (ret);
}
