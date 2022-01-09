/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:08:05 by malton            #+#    #+#             */
/*   Updated: 2021/12/24 20:08:07 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	extract_pathline(char **env, t_info *info)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			info->pathline = env[i] + 5;
		i++;
	}
}

char	*part_path(char **env, t_info *info, char *cmd)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	char	**path_split;

	i = 0;
	if (!strncmp(cmd, "/", 1))
		return (cmd);
	extract_pathline(env, info);
	path_split = ft_split(info->pathline, ':');
	while (path_split[i])
	{
		tmp1 = ft_strjoin(path_split[i], "/");
		tmp2 = ft_strjoin(tmp1, cmd);
		free(tmp1);
		if (access(tmp2, F_OK | X_OK) == 0)
		{
			ft_tab_free(path_split);
			return (tmp2);
		}
		free(tmp2);
		i++;
	}
	ft_tab_free(path_split);
	return (NULL);
}
