/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:24 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:15:35 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int				i;
	int				sign;
	long int		res;

	i = 0;
	res = 0;
	sign = 0;
	if ((string[i] < '0' || string[i] > '9')
		&& (string[i] < '\t' || string[i] > '\r')
		&& (string[i] != ' ') && (string[i] != '-') && (string[i] != '+'))
		return (0);
	while ((string[i] >= '\t' && string[i] <= '\r') || (string[i] == ' ')
		|| (string[i] == '0'))
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
		res = res * 10 + (string[i++] - '0');
	if (sign == -1)
		return (res * sign);
	return ((int)res);
}
