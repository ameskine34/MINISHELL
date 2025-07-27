/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:45:26 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/19 20:29:48 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void ft_pwd(void)
{
    char *path;

    path = getcwd(NULL, 0);
    if (!path)
    {
        write(1, "cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory", 107);
        exit(1);//to review 
    }
    write (1, path, ft_strlen(path));
    write (1, "\n", 1);
    free(path);
}