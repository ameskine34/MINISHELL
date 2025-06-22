/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:04:34 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/22 22:59:29 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

typedef struct s_list
{
   void  *content;
   struct s_list *next;
} t_list;

typedef struct s_env
{
	char			*key;
	char			*value;
}					t_env;

//  typedef struct s_list1
//  {
//    char **my_env;
//  }  t_env;

// typedef struct s_list2
// {
//    // t_env env;
//    char **my_env;
//    // int prev_exit;
//    //  char *key;
//    //  char *value;
//    //  char *next;
// }  t_n;

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
# include <stdarg.h>
#include <fcntl.h> //if you don t use it remove it

int ft_strcmp(char *s1, char *s2);
t_list *ft_new_node(void *content);
t_list *ft_last(t_list *lst);
void ft_add_back(t_list **lst, t_list *new);
void is_built_in(t_list *lst, t_env *lst1);
char *ft_strdup(char *s);
int ft_strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
int ft_strchr(char *str, char s);
int ft_strncmp(char *s1, char *s2, int n);
int ft_lst_size(t_list *lst);
void ft_pwd(void);
void ft_cd(t_list *lst, t_env *lst1);
void pwd_changes(t_env *lst1, char *current, char *new);
void ft_exit(t_list *lst);
long ft_atoi(char *str, int *error);
void ft_echo(t_list *lst, t_env *lst1);
int	ft_putstr(char *s);
int	ft_putchar(unsigned char c);
int	ft_check_f(char c, va_list list);
int	ft_printf(const char *s, ...);
void    ft_export(t_list *lst, t_env *lst1);
void sort(t_env *lst1);
void    set_envi(t_list **envi, char *env);
char	*ft_substr(char *s, unsigned int start, size_t len);
char    *get_key(char *env);

#endif
