/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:52 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c && *s != '\0')
		{
			s++;
		}
		else
		{
			count++;
			s++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

static char	**malloc_arr(char const *s, char c, int *n_words)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	*n_words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (*n_words + 1));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		n_words;
	char	**arr;
	char	**begin;
	int		i;

	arr = malloc_arr(s, c, &n_words);
	arr[n_words] = NULL;
	begin = arr;
	while (n_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		*arr = (char *)malloc(sizeof(char) * (ft_strlen_sep(s, c) + 1));
		if (*arr == NULL)
			return (ft_free_str_arr(&begin));
		i = 0;
		while (*s != c && *s != '\0')
			(*arr)[i++] = *s++;
		(*arr)[i] = '\0';
		arr++;
	}
	return (begin);
}
