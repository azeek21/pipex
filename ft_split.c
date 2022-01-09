/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:26:50 by malton            #+#    #+#             */
/*   Updated: 2021/12/08 10:26:52 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_wordcount(char *s, char c)
{
	size_t	i;
	size_t	total;

	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			total++;
		}
		else
			i++;
	}
	return (total);
}

void	main_creator(char *s, char c, size_t total, char **table)
{
	size_t	wordlen;
	size_t	table_i;
	size_t	string_i;

	table_i = 0;
	string_i = 0;
	while (s[string_i] && table_i < total)
	{
		wordlen = 0;
		if (s[string_i] != c)
		{
			while (s[string_i + wordlen] != c && s[string_i + wordlen])
				wordlen++;
			table[table_i] = ft_calloc(sizeof(char), wordlen + 1);
			if (!table[table_i])
				return ;
			ft_strlcpy(table[table_i], s + string_i, wordlen + 1);
			table_i++;
		}
		string_i = string_i + wordlen + 1;
	}
}

char	**ft_split(char *s, char c)
{
	size_t	total;
	char	**table;

	if (!s)
		return (0);
	total = ft_wordcount((char *)s, c);
	table = ft_calloc(sizeof(char *), total + 1);
	if (!table)
		return (NULL);
	table[total + 1] = NULL;
	main_creator((char *)s, c, total, table);
	return (table);
}

void	ft_exit(char	*str)
{
	ft_putstr(str, 0, 0);
	ft_putchar('\n', 0, 0);
	exit(1);
}
