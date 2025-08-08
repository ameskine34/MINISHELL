/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:05:03 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/08 22:32:27 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	update_or_add_env(t_list **env, char *key, char *value,
		int *is_equal_sign)
{
	t_list	*envi;

	envi = *env;
	while (envi)
	{
		if (((t_env *)envi->content)->key
			&& !ft_strcmp(((t_env *)envi->content)->key, key) && *is_equal_sign)
		{
			(((t_env *)envi->content)->value) = ft_strdup(value);
			return ;
		}
		else if (((t_env *)envi->content)->key
			&& !ft_strcmp(((t_env *)envi->content)->key, key)
			&& !*is_equal_sign)
			return ;
		envi = envi->next;
	}
	ft_lstadd_back(env, ft_lstnew(init_env(ft_strdup(key), ft_strdup(value))));
}

static void	print_exported_env(t_list *temp_env)
{
	while (temp_env)
	{
		print_key(temp_env);
		if (((t_env *)temp_env->content)->value)
		{
			if (((t_env *)temp_env->content)->value[0] == '\0')
			{
				write(1, "=\"\"\n", 4);
				break ;
			}
			if (((t_env *)temp_env->content)->value[0] != '\"')
				write(1, "=\"", 2);
			else
				write(1, "=", 1);
			write(1, ((t_env *)temp_env->content)->value,
				ft_strlen(((t_env *)temp_env->content)->value));
			if (((t_env *)temp_env->content)->value[
					ft_strlen(((t_env *)temp_env->content)->value) - 1] != '"')
				write(1, "\"", 1);
			write(1, "\n", 1);
		}
		temp_env = temp_env->next;
	}
}

static void	extract_key_value(char *arg_content, char **key, char **value,
		int *is_equal_sign)
{
	char	*equal_sign;

	equal_sign = ft_strchr(arg_content, '=');
	if (equal_sign)
	{
		*is_equal_sign = 1;
		*key = ft_substr(arg_content, 0, equal_sign - arg_content);
		*value = ft_strdup(equal_sign + 1);
	}
	else
	{
		*is_equal_sign = 0;
		*key = ft_strdup(arg_content);
		*value = NULL;
	}
}

static void	process_export_arg(t_list **env, char *arg_content)
{
	char	*value;
	char	*key;
	int		is_equal_sign;

	extract_key_value(arg_content, &key, &value, &is_equal_sign);
	if (!is_valid_key(key))
		handle_invalid_key_error(arg_content, key, value);
	else
		update_or_add_env(env, key, value, &is_equal_sign);
}

void	ft_export(t_list *lst, t_list *env)
{
	t_list	*temp_env;
	t_list	*args;

	*exit_status() = 0;
	args = lst->next;
	temp_env = NULL;
	if (ft_lstsize(lst) == 1)
	{
		sort_list(env);
		temp_env = env;
		print_exported_env(temp_env);
		*exit_status() = 0;
	}
	else
	{
		while (args)
		{
			process_export_arg(&env, args->content);
			args = args->next;
		}
	}
}
