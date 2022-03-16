/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:24:20 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_new_s(char **new_s, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(new_s[i]);
		i++;
	}
	free(new_s);
}

static void	mem_cnt(char **new_s, size_t cnt, size_t j)
{
	new_s[j] = malloc(sizeof(char) * (cnt + 1));
	if (new_s[j] == 0)
		free_new_s(new_s, j);
}

static void	mem_new_s(char **new_s, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	j = 0;
	cnt = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			cnt++;
		else if (s[i] == c && s[i - 1] != c)
		{
			mem_cnt(new_s, cnt, j);
			j++;
			cnt = 0;
		}
		if (s[i] != c && s[i + 1] == '\0')
			mem_cnt(new_s, cnt, j);
		i++;
	}
}

static void	fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	row;
	size_t	col;

	i = 0;
	row = 0;
	col = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			tab[col][row++] = s[i];
		else if (s[i] == c && s[i - 1] != c)
		{
			tab[col++][row] = '\0';
			row = 0;
		}
		if (s[i] != c && s[i + 1] == '\0')
			tab[col++][row] = '\0';
		i++;
	}
	tab[col] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] == c)
		i++;
	i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	j++;
	new_str = malloc(sizeof(char *) * (j + 1));
	if (new_str == 0)
		return (NULL);
	mem_new_s(new_str, s, c);
	fill_tab(new_str, s, c);
	return (new_str);
}
