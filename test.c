#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
# include <stdarg.h>
#include <fcntl.h> 

int main()
{
    printf("%s", getcwd(NULL, 0));
}

void sort(t_list *envi)
{
    char *temp;
    int i;
    int j;
    t_list *lst;

    lst = envi;
    envi = envi->next;
    while (((t_env *)envi->content)->key)
    {
        while (((t_env *)envi->next->content)->key)
        {
            if (ft_strcmp(((t_env *)envi->content)->key, ((t_env *)envi->next->content)->key > 0)
            {
               temp =  ((t_env *)envi)->content[i];
               (t_env *)envi)->content[i] = ((t_env *)envi)->content[j];
               ((t_env *)envi)->content[j] = temp;
            }
            j++;
        }
        i++;
    }
}