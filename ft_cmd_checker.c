/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <malton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:11:32 by malton            #+#    #+#             */
/*   Updated: 2022/01/12 18:31:50 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_cmd_checker(char **argv)
{
	if (ft_strlen(argv[2]) == 0)
		ft_exit("First command is empty ?!\n", 127);
	else if (ft_strlen(argv[3]) == 0)
		ft_exit("Second command is empty !?\n", 127);
	if (!ft_strncmp(argv[2], "/", 1))
		if (access(argv[2], F_OK | X_OK) != 0)
			ft_exit("Wrong absolute path\n", 127);
	if (!ft_strncmp(argv[3], "/", 1))
		if (access(argv[3], F_OK | X_OK) != 0)
			ft_exit("Wrong absolute path\n", 127);
	return (0);
}

void	ft_exit(char *str, int i)
{
	ft_putstr(str, 1, 2);
	exit(i);
}
