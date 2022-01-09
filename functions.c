/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:13:15 by malton            #+#    #+#             */
/*   Updated: 2021/12/06 15:13:17 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar(const char c, int to_fd, int fd)
{
	if (to_fd)
		write(fd, &c, 1);
	else
		write(1, &c, 1);
}

void	ft_putstr(char *str, int to_fd, int fd)
{
	int	i;

	i = 0;
	if (to_fd)
	{
		while (str[i])
		{
			write(fd, &str[i], 1);
			i++;
		}
		return ;
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i != n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = (void *)malloc(size * count);
	if (!result)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}
