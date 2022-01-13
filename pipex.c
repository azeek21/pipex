/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:12:30 by malton            #+#    #+#             */
/*   Updated: 2021/12/06 15:12:33 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_info	info;

	if (argc != 5)
	{
		ft_putendl_to_fd("Wrong number of arguments ! Must be 4 arguments", 2);
		ft_putendl_to_fd("Usage: ./pipex file1 command1 command2 file2", 2);
		exit(1);
	}
	if (ft_cmd_checker(argv))
		return (0);
	if (pipe(info.fd_pipe) == -1)
	{
		ft_putendl_to_fd("pipe failed !", 2);
		exit(1);
	}
	pipex_process(&info, argv, env);
	ft_free(&info);
	close(info.fd_outfile);
	close(info.fd_infile);
	return (EXIT_SUCCESS);
}
