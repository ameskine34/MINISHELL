/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:19:11 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/08 22:33:19 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

char	*search_in_env(t_list *envi, char *str)
{
	char	*s;

	s = NULL;
	while (envi)
	{
		if (!ft_strcmp(str, ((t_env *)envi->content)->key))
		{
			s = ft_strdup(((t_env *)envi->content)->value);
			return (s);
		}
		envi = envi->next;
	}
	return (NULL);
}

int	is_built_in(t_list *lst)
{
	if (!lst)
		return (0);
	if (!ft_strcmp(lst->content, "cd"))
		return (1);
	else if (!ft_strcmp(lst->content, "pwd"))
		return (1);
	else if (!ft_strcmp(lst->content, "export"))
		return (1);
	else if (!ft_strcmp(lst->content, "echo"))
		return (1);
	else if (!ft_strcmp(lst->content, "env"))
		return (1);
	else if (!ft_strcmp(lst->content, "exit"))
		return (1);
	else if (!ft_strcmp(lst->content, "unset"))
		return (1);
	else
		return (0);
}

char	*ft_strcat(char *dst, char *s1, char *s2, char *s3)
{
	size_t	i;

	i = 0;
	while (*s1)
	{
		dst[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		dst[i] = *s2;
		i++;
		s2++;
	}
	while (*s3)
	{
		dst[i] = *s3;
		i++;
		s3++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_tree(char *s1, char *s2, char *s3)
{
	char	*join;

	if (!s1 || !s2 || !s3)
		return (NULL);
	join = (char *)gc_malloc((ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1)
			* sizeof(char));
	if (!join)
		return (NULL);
	join = ft_strcat(join, s1, s2, s3);
	return (join);
}

void	print_key(t_list *temp_env)
{
	if (((t_env *)temp_env->content)->key)
	{
		write(1, "declare -x ", 11);
		write(1, ((t_env *)temp_env->content)->key,
			ft_strlen(((t_env *)temp_env->content)->key));
		if (!((t_env *)temp_env->content)->value)
			write(1, "\n", 1);
	}	
}
