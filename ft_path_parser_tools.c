/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_parser_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:13:38 by malton            #+#    #+#             */
/*   Updated: 2021/12/10 17:13:42 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* SINGLE QUOTE (') = 39 */
void	single_quote(char *str, char **res, t_parsing *tab)
{
	tab->i++;
	res[tab->j] = ft_calloc(sizeof(char), ft_tab_len(str, 39, tab->i) + 1);
	if (!res)
		return ;
	while (str[tab->i] != '\0' && str[tab->i] != 39)
		res[tab->j][tab->count++] = str[tab->i++];
}

/* DOUBLE QUOTE (") = 34 */
void	double_quote(char *str, char **res, t_parsing *tab)
{
	tab->i++;
	res[tab->j] = ft_calloc(sizeof(char), ft_tab_len(str, 34, tab->i) + 1);
	if (!res)
		return ;
	while (str[tab->i] != '\0' && str[tab->i] != 34)
		res[tab->j][tab->count++] = str[tab->i++];
}

/* SPACE = 32 */
void	space_case(char *str, char **res, t_parsing *tab)
{
	res[tab->j] = ft_calloc(sizeof(char), ft_tab_len(str, 32, tab->i) + 1);
	if (!res)
		return ;
	while (str[tab->i] != '\0' && str[tab->i] != 32)
		res[tab->j][tab->count++] = str[tab->i++];
}
