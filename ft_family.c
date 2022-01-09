/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_family.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:35:09 by malton            #+#    #+#             */
/*   Updated: 2021/12/10 19:35:11 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	pipex_process(t_info *info, char **av, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putendl_to_fd("fork failed", 2);
		exit(0);
	}
	else if (pid == 0)
		child_process(info, av, env);
	else if (pid > 0)
		parents_process(info, av, env, &pid);
}

void	child_process(t_info *info, char **av, char **env)
{
	info->fd_infile = open(av[1], O_RDONLY);
	if (info->fd_infile < 0)
	{
		ft_putendl_to_fd("file1(input) doesn't exitst", 2);
		exit(1);
	}
	close(info->fd_pipe[0]);
	dup2(info->fd_pipe[1], STDOUT_FILENO);
	close(info->fd_pipe[1]);
	dup2(info->fd_infile, STDIN_FILENO);
	info->cmd_arg = str_parser(av[2]);
	info->path = part_path(env, info, info->cmd_arg[0]);
	if (execve(info->path, info->cmd_arg, env) == -1)
	{
		ft_putstr("command not found: ", 1, 2);
		ft_putendl_to_fd(info->cmd_arg[0], 2);
		ft_free(info);
		exit(1);
	}
}

void	parents_process(t_info *info, char **av, char **env, pid_t *pid)
{
	waitpid(*pid, &info->pid_status, WNOHANG);
	info->fd_outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->fd_outfile < 0)
	{
		exit(1);
	}
	close(info->fd_pipe[1]);
	dup2(info->fd_pipe[0], STDIN_FILENO);
	close(info->fd_pipe[0]);
	dup2(info->fd_outfile, STDOUT_FILENO);
	info->cmd_arg = str_parser(av[3]);
	info->path = part_path(env, info, info->cmd_arg[0]);
	if (execve(info->path, info->cmd_arg, env) == -1)
	{
		ft_putstr("command not found: ", 1, 2);
		ft_putendl_to_fd(info->cmd_arg[0], 2);
		ft_free(info);
		exit(1);
	}
}
