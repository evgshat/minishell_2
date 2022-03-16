/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:24 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:28:24 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char *str)
{
	if (*str == ' '
		|| *str == '\f'
		|| *str == '\n'
		|| *str == '\r'
		|| *str == '\t'
		|| *str == '\v')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	plus_or_minus(int k_minus)
{
	if (k_minus % 2 == 0)
		return (1);
	else
		return (-1);
}

static int	ckeck_supremum_infinum(long return_number, int k_minus_plus)
{
	if ((return_number > 2147483647 && k_minus_plus == 0)
		|| (return_number >= 2147483648 && k_minus_plus == 1))
	{
		if (k_minus_plus == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	return_number;
	int		k_minus_plus;

	return_number = 0;
	i = 0;
	while (is_space(&str[i]))
		i++;
	k_minus_plus = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k_minus_plus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ckeck_supremum_infinum(return_number, k_minus_plus) == 1)
			return (1);
		if (ckeck_supremum_infinum(return_number, k_minus_plus) == -1)
			return (-1);
		return_number = str[i] + return_number * 10 - '0';
		i++;
	}
	return (plus_or_minus(k_minus_plus) * return_number);
}
