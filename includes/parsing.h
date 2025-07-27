
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/27 11:27:36 by yaithadd          #+#    #+#             */
/*   Updated: 2025/06/02 14:10:19 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../tools/libft.h"
# include "libs.h"

# define UNEXPECTED_TOKEN 1
# define CMD_NODE 1
# define ENV_NODE 2
# define INFOS_NODE 3

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
	TOKEN_SPACE,
	TOKEN_OPERATION,
} t_token_type;

typedef struct s_cmd
{
	int has_ambiguous_redir;
	char *heredoc_filename;
	t_list *command_head;
	char **subcomponents;
	char **composed_exp;
	char **resolved_exp;
	char **arr_content;
	t_token_type type;
	char *component;
	char **raw_exp;
	int index;
} t_cmd;

typedef struct s_env
{
	char *value;
	char *key;
} t_env;

typedef struct s_node_infos
{
	int num_of_processes;
	int num_of_pipes;
	int shell_level;
	int pipe_fd[2];
	t_list *data;
	t_list *head;
	t_list *env;
	int in_fd;
	int index;
} t_node_infos;

// * parsing functions:
void	save_data_list_between_d_quotes(t_list **data, char *content);
t_cmd	*init_cmd_node(char *component, char **subcomponents);
t_node_infos	*init_node_infos(t_list *data, t_list *env);
char	*get_resolved_exp(t_cmd *cmd_node, int with_quotes);
char	*get_raw_exp(t_cmd *cmd_node, int with_quotes);
void	split_env_value(t_list **data, char *content);
void	init_env_list(char **env_, t_list **env);
void	save_data_list(char *str, t_list **data);
int		double_single_quotes_syntax(char *str);
void	pars_input(char *str, t_list **data);
char	*expand_expression(char *expression);
void	syntax_error(int err, char *token);
t_env	*get_env(t_list *list, char *key);
void	init_expressions(t_list *data);
void	join_data_list(t_list **data);
void	init_data_list(t_list **head);
int		check_syntax(t_list *data);
void	tokenization(t_list *data);
void	join_cmds(t_list *data);
void	indexing(t_list *data);
void	heredoc(t_list *data);
int		ambiguous(char *str);
// void	set_env(t_list **env_, char *env);
// void	set_env(t_list **env, char *env_);

// ! utils parsing functions:
int	check_for_operations(t_list *data);
int	check_for_redirections(char *str);
int	check_for_char(char *content, char ch);
void	skip_white_spaces(char *str, int *i);
t_cmd	*add_node(t_list **data, char *component, char **subcomponents);
int	check_for_string(char *expected, char *actual);
char	*get_expression_content(char *word);

// & free

// ~ exit code
int	*exit_status(void);

// ^ count lines;
int	*count_lines(void);

// * error
void	syscall_error(char *token);


// ? execution defenitions:
void	execution(t_node_infos *infos);
#endif