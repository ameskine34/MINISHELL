# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 18:02:22 by ameskine          #+#    #+#              #
#    Updated: 2025/06/20 18:18:19 by ameskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = mini_exec.c helper_functions.c env.c ft_printf.c processing.c built_in_export.c built_in_pwd.c built_in_cd.c built_in_echo.c built_in_exit.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	rm -f $(OBJ)

fclean: 
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY = all clean fclean re