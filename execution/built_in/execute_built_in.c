/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:11:52 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/25 16:56:35 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void execute_built_in(t_list *lst, t_list **env)
{
    if (!ft_strcmp(lst->content, "cd"))
        ft_cd(lst, *env);
    else if (!ft_strcmp(lst->content, "pwd"))
        ft_pwd();
    else if (!ft_strcmp(lst->content, "export"))
        ft_export(lst, *env);
    else if (!ft_strcmp(lst->content, "echo"))
        ft_echo(lst);
    else if (!ft_strcmp(lst->content, "env"))
        ft_env(*env);
    else if (!ft_strcmp(lst->content, "exit"))
        ft_exit(lst);
    else if (!ft_strcmp(lst->content, "unset"))
        ft_unset(lst, env);
    else
        return ;
}
// void    execution_phase(t_list *data, t_list *env)
// {   
//     if (!data || !data->content)
//         return;
//     is_built_in(data, &env);
//     // if ()
//     //     executing_one_command();
// }