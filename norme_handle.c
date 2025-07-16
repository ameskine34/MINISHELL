#include "minishell.h"

void pwd_changes(t_list *envi, char *current, char *new)
{
    while (envi)
    {
        if (!ft_strncmp("PWD", ((t_env*)envi->content)->key, 3))
        {
            free(((t_env *)envi->content)->value);
            ((t_env *)envi->content)->value = ft_strdup(new);
        }
        else if (!ft_strncmp("OLDPWD", ((t_env*)envi->content)->key, 6))
        {
            free(((t_env *)envi->content)->value);
            ((t_env *)envi->content)->value = ft_strdup(current);
        }
        envi = envi->next;
    }
}
 
static void ft_cd_change_dir(t_list *lst, t_list *envi, char *current)
{
    char *new;

    new = NULL;
    if (!chdir(lst->next->content))
    {
        new = getcwd(NULL, 0); // will be the new PWD
        pwd_changes(envi, current, new);
        free(current);
        free(new);
    }
    else if (!ft_strncmp("..", lst->next->content, 2) && chdir(lst->next->content))
    {
        ft_printf("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory");
        free(current);
        exit(0);
    }
    else
    {
        ft_printf("bash: cd: ");
        ft_printf("%s", lst->next->content);
        ft_printf(" No such file or directory\n");
        free(current);
        exit(1);
    }
}


void ft_cd(t_list *lst, t_list *envi)
{
    char *current;
    char *new;
    int k;
    
    k = ft_lst_size(lst);
    if (k == 1)
    {
        current = getcwd(NULL, 0); // will be the new OLDPWD
        if (!chdir(getenv("HOME")))
        {
            new = getcwd(NULL, 0); // will be the new PWD
            pwd_changes(envi, current, new);
            free(current);
            free(new);
        }
    }
    else if (k == 2)
    {
        current = getcwd(NULL, 0); // will be the new OLDPWD
        ft_cd_change_dir(lst, envi, current);
    }
    else if (k > 2)
    {
        ft_printf("bash: cd: too many arguments\n");
        exit(1);
    }
}
