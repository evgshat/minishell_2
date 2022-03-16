/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:10:59 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:11:12 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

long long	atoi_for_exit(char *str)
{
	int			i;
	long long	return_number;
	int			k_minus_plus;

	i = 0;
	return_number = 0;
	k_minus_plus = 1;
	if (str == NULL)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			k_minus_plus *= -1;
		str++;
	}
	while (*str != '\0')
	{
		if ((*str >= '0') && (*str <= '9'))
			return_number = return_number * 10 + (*str) - '0';
		else
			break ;
		str++;
	}
	return (k_minus_plus * return_number);
}

int	chech_str_is_digits(char *str)
{
	int	i;
	int	exit_flag;

	exit_flag = 0;
	i = 0;
	if (str[i] == '-')
		++i;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == false)
			exit_flag = 1;
		i++;
	}
	if (exit_flag == 1)
		return (false);
	return (true);
}

int	one_argumnet_exit(char *arg, t_main *prmtrs)
{
	long long	exit_number;

	if (chech_str_is_digits(arg) == true
		&& (ft_strcmp(arg, "9223372036854775807") <= 0
			|| ft_strcmp(arg, "-9223372036854775808") <= 0))
	{
		exit_number = atoi_for_exit(arg);
		prmtrs->exit_status = ((exit_number + 256) % 256);
		free_prmtrs(prmtrs, SUCCESSFUL_EXIT);
		exit(prmtrs->exit_status);
	}
	else
	{
		printf("my_shell: exit: %s: numeric argument required\n", arg);
		free_prmtrs(prmtrs, SUCCESSFUL_EXIT);
		exit(255);
	}
	return (0);
}

int	several_arguments_exit(t_main *prmtrs)
{
	prmtrs->exit_status = 1;
	printf("my_shell: exit: too many arguments\n");
	return (0);
}

int	cmd_exit(char **cmnd_words, t_main *prmtrs)
{
	if (cmnd_words[1] == NULL)
	{
		ft_putstr_fd("exit", 1);
		free_prmtrs(prmtrs, SUCCESSFUL_EXIT);
		exit(prmtrs->exit_status);
	}
	if (cmnd_words[2] == NULL)
		one_argumnet_exit(cmnd_words[1], prmtrs);
	else
		several_arguments_exit(prmtrs);
	return (0);
}
