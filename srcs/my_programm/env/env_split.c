/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:41 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:33:42 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	count_words_check_equality(char const *s,
										 int *n_words, int *flag_empty_second)
{
	*n_words = 1;
	while (*s != '\0')
	{
		if (*s == '=')
		{
			*n_words = 2;
			s++;
			if (*s == '\0')
				*flag_empty_second = true;
			else
				*flag_empty_second = false;
			break ;
		}
		else
			s++;
	}
}

static char	**malloc_arr(char const *s, int *n_words, int *flag_empty_second)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	count_words_check_equality(s, n_words, flag_empty_second);
	arr = (char **)malloc(sizeof(char *) * (*n_words + 1));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

char	**env_split(char const *s)
{
	char	**arr;
	int		flag_empty_second;
	int		n_words;

	arr = malloc_arr(s, &n_words, &flag_empty_second);
	arr[n_words] = NULL;
	if (n_words == 1)
		arr[0] = ft_strdup_sep(s, '=');
	if (n_words == 2 && flag_empty_second == false)
	{
		arr[0] = ft_strdup_sep(s, '=');
		while (*s != '=')
			s++;
		s++;
		arr[1] = ft_strdup(s);
	}
	if (n_words == 2 && flag_empty_second == true)
	{
		arr[0] = ft_strdup_sep(s, '=');
		arr[1] = ft_strdup("\0");
	}
	return (arr);
}
