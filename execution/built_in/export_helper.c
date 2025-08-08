/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:10:29 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/03 19:43:54 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	swap_env_nodes(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

void	sort_list(t_list *env)
{
	t_list	*env_current;
	t_list	*env_next;

	env_current = env;
	if (env == NULL)
		return ;
	while (env_current)
	{
		env_next = env_current->next;
		while (env_next)
		{
			if (ft_strcmp(((t_env *)env_current->content)->key,
					((t_env *)env_next->content)->key) > 0)
				swap_env_nodes(env_current, env_next);
			env_next = env_next->next;
		}
		env_current = env_current->next;
	}
}

int	is_alphanum_or_underscore(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9') || c == '_');
}

int	is_valid_key(char *key)
{
	int	i;

	if (!key || !key[0])
		return (0);
	if (!((key[0] >= 'A' && key[0] <= 'Z') || (key[0] >= 'a' && key[0] <= 'z')
			|| key[0] == '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if (!is_alphanum_or_underscore(key[i]))
			return (0);
		i++;
	}
	return (1);
}

void	handle_invalid_key_error(char *arg_content, char *key, char *value)
{
	(void)key;
	(void)value;
	write(2, "minishell: export: `", 20);
	write(2, arg_content, ft_strlen(arg_content));
	write(2, "\': not a valid identifier\n", 26);
	*exit_status() = 1;
}
