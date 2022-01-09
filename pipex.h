/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:12:55 by malton            #+#    #+#             */
/*   Updated: 2021/12/06 15:12:57 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_parsing {
	int	len;
	int	i;
	int	j;
	int	count;
}	t_parsing;

typedef struct s_info {
	int		fd_infile;
	int		fd_outfile;
	int		fd_pipe[2];
	int		pid_status;
	char	*pathline;
	char	**env;
	char	*path;
	char	**cmd_arg;
}	t_info;

void	ft_putchar(const char c, int to_fd, int fd);
void	ft_putstr(char *str, int to_fd, int fd);
size_t	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_putendl_to_fd(char *s, int fd);
void	ft_free(t_info *info);
void	ft_tab_free(char **str);
size_t	ft_wordcount(char *s, char c);
void	main_creator(char *s, char c, size_t total, char **table);
char	**ft_split(char *s, char c);
void	ft_exit(char	*str);
void	child_process(t_info *info, char **av, char **env);
void	parents_process(t_info *info, char **av, char **env, pid_t *pid);
void	pipex_process(t_info *info, char **av, char **env);
void	extract_pathline(char **env, t_info *info);
char	*part_path(char **env, t_info *info, char *cmd);
void	single_quote(char *str, char **res, t_parsing *tab);
void	double_quote(char *str, char **res, t_parsing	*tab);
void	space_case(char	*str, char **res, t_parsing	*tab);
void	word_count(char *str, int *i, int *count);
int		count_bunch(char *str);
int		ft_tab_len(char	*s, char c, int i);
char	**parsing_malloc_str(char *str, char **res, t_parsing *tab);
char	**str_parser(char *str);
int		main(int argc, char **argv, char **env);

#endif
