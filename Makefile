PARSING_SRC = minishell.c parsing/ambiguous.c parsing/double_single_quotes_syntax.c parsing/expand_expression.c parsing/init_heredoc.c parsing/indexing.c parsing/init_data_list.c \
			parsing/init_env_list.c parsing/init_expressions.c parsing/init_nodes.c parsing/join_cmds.c parsing/join_data_list.c parsing/parsing.c \
			parsing/save_data_list_between_d_quotes.c parsing/save_data_list.c parsing/split_env_value.c parsing/syntax.c parsing/tokenization.c\
			parsing/init_subcomponents.c

PARSING_UTILS_SRC = parsing/utils/add_node.c parsing/utils/checks_.c parsing/utils/count_lines.c parsing/utils/exit_status.c parsing/utils/gc_malloc.c \
			parsing/utils/get_env.c parsing/utils/get_expression_content.c parsing/utils/get_num_of_pipes.c parsing/utils/get_target_action.c \
			parsing/utils/init_signals.c parsing/utils/save_data_list_utils.c parsing/utils/set_exit_status.c parsing/utils/set_get_target_action.c \
			parsing/utils/skip_white_spaces.c parsing/utils/syn_error.c parsing/utils/gc_fds.c parsing/utils/init_heredoc_utils.c parsing/utils/syntax_utils.c\
			parsing/utils/safe_open.c

EXECUTION_SRC = execution/dup_redirections.c execution/err_or.c execution/execute_cmd.c execution/execute.c execution/file_error.c execution/get_valid_path.c \
			execution/init_processes.c 

EXECUTION_BUILT_IT_SRC = execution/built_in/built_in_cd.c execution/built_in/built_in_echo.c execution/built_in/built_in_env.c execution/built_in/built_in_exit.c \
			execution/built_in/built_in_export.c execution/built_in/built_in_pwd.c execution/built_in/built_in_unset.c execution/built_in/execute_built_in.c \
			execution/built_in/helper_function.c execution/built_in/export_helper.c execution/built_in/atol_for_exit.c

OBJS = ${PARSING_SRC:.c=.o} ${PARSING_UTILS_SRC:.c=.o} ${EXECUTION_SRC:.c=.o} ${EXECUTION_BUILT_IT_SRC:.c=.o}

NAME = minishell

LIB_DIR = tools

LIB_TARGET = ${LIB_DIR}/libft.a

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L${LIB_DIR} -lft -lreadline

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

all: ${LIB_TARGET} ${NAME}

${LIB_TARGET}:
	@echo "📦 Building mandatory libft..."
	@make --no-print-directory -C $(LIB_DIR)
	@echo "✨ Building bonus part of libft..."
	@make --no-print-directory -C $(LIB_DIR) bonus

${NAME}: ${OBJS}
	@echo "📦 Building minishell..."
	@${CC}  ${OBJS} ${LDFLAGS} -o ${NAME}

clean:
	@echo "📦 Cleaning libft..."
	@make --no-print-directory -C $(LIB_DIR) clean
	@echo "📦 Cleaning minishell..."
	@${RM} ${OBJS}

fclean: clean
	@echo "📦 Cleaning libft..."
	@make --no-print-directory -C $(LIB_DIR) fclean
	@echo "📦 Cleaning minishell..."
	@${RM} ${OBJS} ${NAME}

re: fclean all

.PHONY: bonus clean all fclean
