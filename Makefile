# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 18:02:22 by ameskine          #+#    #+#              #
#    Updated: 2025/07/03 22:45:11 by ameskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = built_in_echo.c built_in_exit.c built_in_pwd.c ft_printf.c print_env.c set_envi.c built_in_cd.c  built_in_env.c execution.c helper_function.c processing.c
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