/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:38:24 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 16:23:00 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

// int	check_for_redirections(char *content)
// {
// 	if (ft_strncmp(content, "<", ft_strlen(content)) == 0)
// 		return (TOKEN_IN_REDIRECTION);
// 	if (ft_strncmp(content, ">", ft_strlen(content)) == 0)
// 		return (TOKEN_OUT_REDIRECTION_OVERWRITE);
// 	if (ft_strncmp(content, ">>", ft_strlen(content)) == 0)
// 		return (TOKEN_OUT_REDIRECTION_APPEND);
// 	return (0);
// }

void	dup_(t_list *data, int type_of_redirection)
{
	int fd;
	char *content;
	char *file_name;

	content = ((t_cmd *)data->content)->component;
	if (data->next)
		file_name = ((t_cmd *)data->next->content)->component;
	if (type_of_redirection == TOKEN_IN_REDIRECTION)
	{
		fd = open(file_name, O_RDONLY);
		dup2(fd, 0);
	}
	else if (type_of_redirection == TOKEN_OUT_REDIRECTION_OVERWRITE)
	{
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
		dup2(fd, 1);
	}else if (type_of_redirection == TOKEN_OUT_REDIRECTION_APPEND)
	{
		fd = open(file_name, O_RDWR | O_CREAT, 0777);
		dup2(fd, 1);
	}
}

void dup_redirections(t_list *head)
{
	int type_of_redirection;

	type_of_redirection = 0;
	while (head)
	{
		if (((t_cmd *)head->content)->type == TOKEN_PIPE)
			break ;
		type_of_redirection = check_for_redirections(((t_cmd *)head->content)->component); 
		if (type_of_redirection != 0)
			dup_(head, type_of_redirection);
		head = head->next;
	}
}