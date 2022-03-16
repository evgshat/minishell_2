/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:37 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:28:41 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_str_arr(char ***arr)
{
	int	i;

	if (arr == NULL || *arr == NULL)
		return (NULL);
	i = 0;
	if ((*arr) != NULL)
	{
		while ((*arr)[i] != NULL)
		{
			if ((*arr)[i] != NULL)
			{
				free((*arr)[i]);
				(*arr)[i] = NULL;
			}
			i++;
		}
		if (*arr != NULL)
			free(*arr);
		*arr = NULL;
	}
	return (NULL);
}
