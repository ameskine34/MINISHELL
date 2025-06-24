/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:45:26 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/23 16:54:33 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_pwd(void)
{
    char *path;

    path = getcwd(NULL, 0);
    write(1, path, ft_strlen(path));
    free(path);
}