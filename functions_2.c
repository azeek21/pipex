/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:27:20 by malton            #+#    #+#             */
/*   Updated: 2021/12/08 08:27:23 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*copy1;
	unsigned char	*copy2;

	i = 0;
	copy1 = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while ((copy1[i] != '\0' || copy2[i] != '\0') && i < n)
	{
		if (copy1[i] != copy2[i])
			return (copy1[i] - copy2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	j;

	j = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen((char *)s) < start)
		return (ft_strdup(""));
	copy = (char *)malloc((len + 1) * sizeof(char));
	while (s[start] != '\0' && 0 < len)
	{
		copy[j++] = s[start++];
		len--;
	}
	copy[j] = '\0';
	return (copy);
}

void	ft_putendl_to_fd(char *s, int fd)
{
	ft_putstr(s, 1, fd);
	ft_putchar('\n', 1, fd);
}

void	ft_free(t_info *info)
{
	free(info->path);
	ft_tab_free(info->cmd_arg);
	info->path = NULL;
	info->cmd_arg = NULL;
}

void	ft_tab_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
