/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:43:23 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 18:43:23 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../tools/libft.h"
# include "libs.h"

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

# define CODE_UNEXPECTED_TOKEN 1
# define CODE_D_S_Q_SYN_ERR 2

# define MSG_UNEXPECTED_TOKEN_MSG "basha: syntax error near unexpected token "
# define MSG_D_S_Q_SYN_ERR "basha: syntax error: unexpected end of input"

# define MSG_CMD_NOT_FOUND "command not found"       // 127
# define MSG_N_S_F_O_D "No such file or directory"   // 127
# define MSG_PERM_DENIED "Permission denied"         // 126
# define MSG_IS_DIRECTORY "Is a directory"           // 126
# define MSG_FILE_NAME_TOO_LONG "File name too long" // 126
# define MSG_AMB_REDIRECT "ambiguous redirect"       // 1

# define CODE_SYS_CALL 0
# define CODE_CMD_NOT_FOUND 1
# define CODE_N_S_F_O_D 2
# define CODE_PERM_DENIED 3
# define CODE_IS_DIRECTORY 4
# define CODE_FILE_NAME_TO_LONG 5
# define CODE_AMB_REDIRECT 6

typedef enum s_token_type
{
	TOKEN_PIPE = 1,
	TOKEN_OUT_REDIRECTION_OVERWRITE,
	TOKEN_IN_REDIRECTION,
	TOKEN_OUT_REDIRECTION_APPEND,
	TOKEN_HEREDOC,
	TOKEN_FILE,
	TOKEN_COMMAND,
	TOKEN_ARGUMENT,
	TOKEN_WORD,
	TOKEN_SPACE,
	TOKEN_OPERATION,
}	t_token_type;

typedef struct s_cmd
{
	t_token_type		type;
	t_list				*command_head;
	char				*component;
	char				**subcomponents;
	int					has_word;
	char				**raw_exp;
	char				**composed_exp;
	char				**resolved_exp;
	char				**arr_content;
	int					heredoc_fd_read;
	int					index;
	int					has_ambiguous_redir;
	int					skip_node;
	int					skip_dollar;
}	t_cmd;

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_node_infos
{
	char	*cwd;
	int		pipe_fd[2];
	int		in_fd;
	int		index;
	int		num_of_pipes;
	int		num_of_processes;
	t_list	*data;
	t_list	*head;
	t_list	*env;
}	t_node_infos;

int				pars_input(char *str, t_list **data, t_list *env);
int				check_syntax(t_list *data);
void			save_data_list(char *str, t_list **data);
t_cmd			*init_cmd_node(char *component, char **subcomponents);
t_node_infos	*init_node_infos(void);
void			init_data_list(t_list **head, t_list *env);
void			syntax_error(int err, char *token);
void			tokenization(t_list *data);
int				double_single_quotes_syntax(char *str);
void			indexing(t_list *data);
void			join_cmds(t_list *data);
void			save_data_list_between_d_quotes(t_list **data, char *content);
t_env			*get_env(t_list *list, char *key);
char			*expand_expression(char *expression, t_list *env);
char			*expand_double_quotes_var(char *expression, t_list *env);
// void			init_expressions(t_list *data, t_list *env);
void			split_env_value(t_list **data, char *content);
// char			*get_resolved_exp(t_cmd *cmd_node, int with_quotes, 
//t_list *env);
char			*get_raw_exp(t_cmd *cmd_node, int with_quotes);
int				ambiguous(char *str);
void			join_data_list(t_list **data);
void			init_env_list(char **env_, t_list **env);
void			init_subcomponents(t_list *data);
int				init_heredoc(t_list *data, t_list *env);
char			*ft_ranstring(void);
void			heredoc_ctrl_c(int sig);
void			heredoc_ctrl_d(char *delimiter);
// ^ utils parsing functions:
void			save_space(t_list **data, char *str, int *i);
void			save_single_quotes_content(t_list **data, char *str, int *i);
void			save_double_quotes_content(t_list **data, char *str, int *i);
void			save_operations(t_list **data, char *str, int *i);
void			save_var(t_list **data, char *str, int *i);
int				check_for_operations(t_list *data);
int				check_for_redirections(char *str);
int				check_for_char(char *content, char ch);
void			skip_white_spaces(char *str, int *i);
t_cmd			*add_node(t_list **data, char *component, char **subcomponents);
int				check_for_string(char *expected, char *actual);
char			*get_expression_content(char *word);
void			alloc_regulare(void);
void			alloc_env_list(void);
void			free_regulare(void);
void			free_env_list(void);
void			init_signals(void);
int				set_exit_status_code(int status);
int				get_num_of_pipes(t_list *data);
long			*exit_status(void);
int				*count_lines(void);
void			count_line(void);
void			gc_fds(int fd, t_gc_action action);
void			skip_next_space(t_list **data);
void			skip_space_to_prev(t_list **data);
void			skip_space_to_next(t_list **data);
int				safe_open(char *filename, int flags, int is_child);

// * execution functions:
void			execution(t_node_infos *infos);
void			execute_cmd(t_node_infos *infos);
int				dup_redirections(t_list *head, int is_child);
char			*get_path(t_node_infos *infos);
void			init_processes(t_node_infos *infos);
void			execute_built_in(t_list *lst, t_list **env,
					t_node_infos *infos);
int				is_built_in(t_list *lst);
void			err_or(char *token, int code);
void			file_error(char *token, int code, int is_child);
char			*ft_strjoin_tree(char *s1, char *s2, char *s3);
char			*search_in_env(t_list *envi, char *str);

#endif