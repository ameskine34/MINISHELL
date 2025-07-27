/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:24:00 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/25 18:17:16 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*get_key(char *env) 
{
	int		i;
	char	*key;

	i = 0;
	key = NULL;
	while (env[i])
	{
		if (env[i] == '=')
			break ;
		i++;
	}
	key = ft_substr(env, 0, i);
	return (key);
}

char	*get_value(char *env)
{
	char	*value;
	int		i;

	value = NULL;
	i = 0;
	while (env[i])
	{
		if (env[i] == '=')
			break ;
		i++;
	}
	i++;
	value = ft_substr(env, i, ft_strlen(env) - i);
	return (value);
}

t_env	*init_env(char *key, char *value)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->key = key;
	lst->value = value;
	return (lst);
}

void	set_env(t_list **env, char *env__)
{
	t_env	*env_node;

	env_node = NULL;
	env_node = init_env(get_key(env__), get_value(env__));
	if (!env_node)
		return ;
	ft_lstadd_back(env, ft_lstnew(env_node));
}

void	init_env_list(char **env_, t_list **env)
{
	int i;

	i = 0;
	while (env_[i])
	{
		set_env(env, env_[i]);
		i++;
	}
}