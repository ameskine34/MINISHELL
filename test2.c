/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:23:55 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/08 10:59:22 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void    swap_env_nodes(t_list *a, t_list *b)
// {
//     void *tmp;

//     tmp = a->content;
//     a->content = b->content;
//     b->content = tmp;
// }

// void    sort_list(t_list *env)
// {
//     t_list *env_current;
//     t_list *env_next;

//     env_current = env;
//     if (env == NULL)
//         return ;
//     while (env_current)
//     {
//         env_next = env_current->next;
//         while (env_next)
//         {
//             if (ft_strcmp(((char *)env_current->content), ((char *)env_next->content)) > 0)
//             {
//                 swap_env_nodes(env_current, env_next);
//             }
//             env_next = env_next->next;
//         }
//         env_current = env_current->next;
//     }
// }

// int main()
// {
//     t_list *f;

//     int q = 10;
//     int b = 9;
//     int h = 6;
//     int w = 1;

//     ft_add_back(&f, ft_new_node(&q));
//     ft_add_back(&f, ft_new_node(&b));
//     ft_add_back(&f, ft_new_node(&h));
//     ft_add_back(&f, ft_new_node(&w));
//     sort_list(f);
//     while (f)
//     {
//         printf("%d\n", *(int *)f->content);
//         f= f->next;
//     }
// }

// void    swap_env(char **s, char **s2)
// {
//     char *tmp;

//     tmp = *s;
//     *s = *s2;
//     *s2 = tmp;
// }

// void    sort_env(char **env)
// {
//     int i;
//     int j;

//     i = 0;
//     if (!env || !*env)
//         return ;
//     while (env[i])
//     {
//         j = i+1;
//         while (env[j])
//         {
//             if (ft_strcmp(env[i], env[j]) > 0)
//             {
//                 swap_env(&env[i], &env[j]);
//             }
//             j++;
//         }
//         i++;
//     }
// }

// int main()
// {
//     int i = 0;
//     char *s[6] = {"z", "w", "y", "r", "a"};
//     sort_env(s);
//     while(s[i])
//     {
//         printf("%s\n", s[i]);
//         i++;
//     }
// }
// char *ft_strchr1(char *str, char s)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (str[i] == s)
//             return (&str[i]);
//         i++;
//     }
//     return (NULL);
// }
// int main()
// {
//     printf("%s\n", ft_strchr1("amine=like", '='));
// }

// int main()
// {
//     char *s="amine=meskinerkghirwenhnhbfkensk;lfd";
//     char *d = ft_strchr1(s, '=');
//     printf("%d\n", s);
//     printf("%d\n", d);
//     printf("%d\n", d - s);
// }
