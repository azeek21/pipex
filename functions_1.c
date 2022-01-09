/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 05:19:35 by malton            #+#    #+#             */
/*   Updated: 2021/12/08 05:19:38 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strchr(const char *s, int c)
{
	char	*copy;
	char	needle;
	int		i;

	copy = (char *)s;
	needle = c;
	i = 0;
	while (copy[i] != '\0')
	{
		if (copy[i] == needle)
			return (1);
		i++;
	}
	if (copy[i] == c)
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;
	int		length;

	i = 0;
	result = NULL;
	length = ft_strlen((char *)s);
	result = (char *)ft_calloc((length + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (i < length)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dest)
		return (0);
	j = ft_strlen((char *)src);
	if (!size)
		return (j);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	result_length;
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	result_length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!s2 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (result_length + 1));
	if (!result)
		return (NULL);
	while (s1[j])
		result[i++] = (char)s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = (char)s2[j++];
	result[i] = '\0';
	return (result);
}
