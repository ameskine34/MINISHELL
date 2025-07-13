/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:11:52 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/13 19:01:43 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void is_built_in(t_list *lst, t_list **lst1)
{
    if (!ft_strcmp(lst->content, "cd"))
        ft_cd(lst, *lst1);
    else if (!ft_strcmp(lst->content, "pwd"))
        ft_pwd();
    else if (!ft_strcmp(lst->content, "export"))
        ft_export(lst, *lst1);
    else if (!ft_strcmp(lst->content, "echo"))
        ft_echo(lst);
    else if (!ft_strcmp(lst->content, "env"))
        ft_env(*lst1);
    else if (!ft_strcmp(lst->content, "exit"))
        ft_exit(lst);
    // else if (ft_strcmp(lst->content, "unset"))
    //     ft_unset(lst, *lst1);
    else
        return ;
}

void    execution_phase(t_list *data, t_list *env)
{
    // t_node_infos *infos;
    // char **env_arr;
    if (!data || !data->content)
        return;

    // env_arr = from_env_to_arr(env);
    is_built_in(data, &env);
    // is_external_command(((t_cmd*)data->content)->arr_content, env);
    // infos = init_infos();
    // init_pipe(data, infos);
    // init_processes(infos);
}