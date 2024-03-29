/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:06 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:19:30 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int ch)
{
	int	res;

	res = 0;
	if (57 >= ch && ch >= 48)
		res = 1;
	return (res);
}
