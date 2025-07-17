/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:11:52 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/17 22:52:42 by ameskine         ###   ########.fr       */
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
    else if (!ft_strcmp(lst->content, "unset"))
        ft_unset(lst, lst1);
    else
        return ;
}
void    executing_one_command(t_list *data)
{
    ;
} 
void    execution_phase(t_list *data, t_list *env)
{   
    if (!data || !data->content)
        return;
    // is_built_in(data, &env);
    if ()
        executing_one_command();
}