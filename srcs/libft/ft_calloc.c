/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:32 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:17:37 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*new;
	size_t	cnt;

	cnt = number * size;
	new = malloc(cnt);
	if (new == 0)
		return (0);
	ft_bzero(new, cnt);
	return (new);
}
