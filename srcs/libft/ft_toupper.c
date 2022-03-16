/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:14 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:15 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int value)
{
	if (value >= 97 && value <= 122)
	{
		return (value - 32);
	}
	else
	{
		return (value);
	}
}
