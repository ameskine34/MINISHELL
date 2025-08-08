/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:11:52 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/05 16:06:45 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	execute_built_in(t_list *lst, t_list **env, t_node_infos *infos)
{
	if (!ft_strcmp(lst->content, "cd"))
		ft_cd(lst, *env, infos);
	else if (!ft_strcmp(lst->content, "pwd"))
		ft_pwd(*env, infos);
	else if (!ft_strcmp(lst->content, "export"))
		ft_export(lst, *env);
	else if (!ft_strcmp(lst->content, "echo"))
		ft_echo(lst);
	else if (!ft_strcmp(lst->content, "env"))
		ft_env(lst, *env);
	else if (!ft_strcmp(lst->content, "exit"))
		ft_exit(lst, infos);
	else if (!ft_strcmp(lst->content, "unset"))
		ft_unset(lst, env);
	else
		return ;
}
