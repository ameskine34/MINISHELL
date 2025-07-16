/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:03:06 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/16 12:02:10 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int main(int ac, char **av, char **env)
// {
//     int i = 0;
//     t_list *lst;
//     t_list *envi;

//     lst = NULL;
//     envi = NULL;
//     // data = NULL;
//     while (env[i])
//     {
//         set_envi(&envi ,env[i]);
//         i++;
//     }
//     i = 0;
//     while (i < ac)
//     {
//         ft_add_back(&lst, ft_new_node(ft_strdup(av[i+1])));
//         i++;
//     }
//     is_built_in(lst, &envi);
//     while (envi)
//     { 
//         printf("%s", ((t_env *)envi->content)->key);//The (t_env *) typecast is essential for informing the compiler about 
//         // the actual data type stored in the void *content member of your linked list node. 
//         // It allows you to correctly access the key and value members of your t_env structure,
//         //  preventing compilation errors and ensuring proper memory interpretation.
//         printf("%s\n", ((t_env *)envi->content)->value);
//         envi = envi->next;
//     }
// }
int main(int ac, char **av, char **env)
{
    t_list *lst1 = NULL;
    t_list *lst = NULL;
    char **cmd_args;
    char *line;
    int i;

    (void)ac;
    (void)av;
    i = 0;
    while (env[i])
    {
        set_envi(&lst1, env[i]);
        i++;
    }
    while (1)
    {
        line = readline("minishell> ");
        if (!line)
            break ;
        if (ft_strlen(line) > 0)
            add_history(line);
        cmd_args = ft_split(line, ' ');
        if (!cmd_args)
        {
            ft_printf("%s", "Error\n");
            free(line);
            continue;
        }
        i = 0;
        while (cmd_args[i])
        {
            ft_add_back(&lst, ft_new_node(ft_strdup(cmd_args[i])));
            free(cmd_args[i]);
            i++;
        }
        free(cmd_args);
        if (lst && lst->content)
        {
            execution_phase(lst, lst1);
        }
        ft_lst_clear(&lst, free);
        free(line);
    }
    ft_lst_clear(&lst1, free_env_node);
}