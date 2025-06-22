/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:19:11 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/22 22:25:11 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar(unsigned char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

char    *ft_strdup(char *s)
{
        size_t  i;
        char    *dup;

        dup = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
        if (!dup)
                return (NULL);
        i = 0;
        while (s[i])
        {
                dup[i] = s[i];
                i++;
        }
        dup[i] = '\0';
        return (dup);
}

int ft_strchr(char *str, char s)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == s)
            return (1);
        i++;
    }
    return (0);
}

t_list  *ft_new_node(void *content)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

t_list *ft_last(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

int  ft_lst_size(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

void    ft_add_back(t_list **lst, t_list *new)
{   
    t_list *lst1;

    lst1 = *lst;
    if (!lst)
        return ;
    if (!(*lst))
    {
        (*lst) = new;
        return ;
    }
    lst1 = ft_last(lst1);
    lst1->next = new;
}

static char	*ft_strcat(char *dst, char *s1, char *s2)
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
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join = ft_strcat(join, s1, s2);
	return (join);
}

t_env	*init_env_node(char *key, char *value)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = key;
	env->value = value;
	return (env);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	if (len > str_len - start)
		len = str_len - start;
	i = 0;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}