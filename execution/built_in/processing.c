/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:03:06 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/25 18:13:52 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

//^gcc execution/built_in/*.c -Ltools -lft -lreadline

// int main(int ac, char **av, char **env)
// {
//     t_list *lst1 = NULL;
//     t_list *lst = NULL;
//     char **cmd_args;
//     char *line;
//     int i;

//     (void)ac;
//     (void)av;
    
//     while (1)
//     {
//         line = readline("minishell> ");
//         if (!line)
//             break ;
//         if (ft_strlen(line) > 0)
//             add_history(line);
//         cmd_args = ft_split(line, ' ');
//         if (!cmd_args)
//         {
//             printf("%s", "Error\n");
//             free(line);
//             continue;
//         }
//         i = 0;
//         while (cmd_args[i])
//         {
//             ft_lstadd_back(&lst, ft_lstnew(ft_strdup(cmd_args[i])));
//             free(cmd_args[i]);
//             i++;
//         }
//         free(cmd_args);
//         if (lst && lst->content)
//         {
//             execution_phase(lst, lst1);
//         }
//         ft_lst_clear(&lst, free);
//         free(line);
//     }
//     ft_lst_clear(&lst1, free_env_node);
// }
