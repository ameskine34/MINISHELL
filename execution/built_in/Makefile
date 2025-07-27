# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 18:02:22 by ameskine          #+#    #+#              #
#    Updated: 2025/07/19 16:36:52 by yaithadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline -lhistory
SRC = processing.c execution_exec.c built_in_echo.c built_in_export.c built_in_exit.c built_in_pwd.c set_envi.c built_in_cd.c  built_in_env.c helper_function.c built_in_unset.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -L../../tools -lft -o $(NAME)
	
clean:
	rm -f $(OBJ) 

fclean: 
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY = all clean fclean re