/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:04:34 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/09 11:28:01 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

typedef enum s_token_type
{
	TOKEN_PIPE = 1,
	TOKEN_OUT_REDIRECTION_OVERWRITE,
	TOKEN_OUT_REDIRECTION_APPEND,
	TOKEN_IN_REDIRECTION,
	TOKEN_HEREDOC,
	TOKEN_FILE,
	TOKEN_COMMAND,
	TOKEN_ARGUMENT,
}					t_token_type;

typedef enum t_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_list
{
   void  *content;
   struct s_list *next;
} t_list;

typedef struct s_cmd
{
	t_token_type	type;
	char			*content;
	int				index;
	char			**arr_content;
}					t_cmd;

typedef struct s_node_infos
{
	int				shell_level;
	int				exit_status;
	int				**pipes;
	int				index;
	int				num_of_pipes;
	t_list			*data;
	int				num_of_processes;
}					t_node_infos;

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
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h> //if you don t use it remove it

int ft_strcmp(char *s1, char *s2);
t_list *ft_new_node(void *content);
t_list *ft_last(t_list *lst);
void    execution_phase(t_list *data, t_list *env);
void ft_add_back(t_list **lst, t_list *new);
void is_built_in(t_list *lst, t_list **lst1);
char *ft_strdup(char *s);
int ft_strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
int ft_strchr(char *str, char s);
int ft_strncmp(char *s1, char *s2, int n);
int ft_lst_size(t_list *lst);
void ft_pwd(void);
void ft_cd(t_list *lst, t_list *lst1);
void pwd_changes(t_list *envi, char *current, char *new);
void ft_exit(t_list *lst);
long ft_atoi(char *str, int *error);
void ft_echo(t_list *lst);
int	ft_putstr(char *s);
int	ft_putchar(unsigned char c);
int	ft_check_f(char c, va_list list);
int	ft_printf(const char *s, ...);
void    ft_export(t_list *lst, t_list *lst1);
void sort(t_env *lst1);
void    set_envi(t_list **envi, char *env);
char	*ft_substr(char *s, unsigned int start, size_t len);
char    *get_key(char *env);
char	*ft_str_tree_join(char  *s1, char  *s2, char *s3);
char	*ft_str_tree_cat(char *dst, char *s1, char *s2, char *s3);
void	*ft_memset(void *s, int c, size_t n);
char    **from_env_to_arr(t_list *env);
char	*ft_strchr1(char *str, int c);
t_env   *init_env(char *key, char *value);
void    ft_env(t_list *envi);
char	**ft_split(char *s, char c);
void	ft_lst_clear(t_list **lst, void (*del)(void *));
void free_env_node(void *content);
void    update_or_add_env(t_list **env, char *key, char *value);

#endif