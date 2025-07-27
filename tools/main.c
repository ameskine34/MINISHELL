#include "libft.h"
#include <stdio.h>


void	danon(void *content)
{
	free(content);
}

void	*content(void *content)
{
	content = content + 5;
	return (content);
}

void	print(void *content)
{
	printf("%s\n", (char *)content);
}

// int main()
// {
// 	t_list *mylist = NULL;
// 	ft_lstadd_back(&mylist, ft_lstnew("node 1"));
// 	ft_lstadd_back(&mylist, ft_lstnew("node 2"));
// 	ft_lstadd_back(&mylist, ft_lstnew("node 3"));
// 	ft_lstadd_back(&mylist, ft_lstnew("node 4"));
// 	ft_lstadd_back(&mylist, ft_lstnew("node 5"));
// 	ft_lstadd_back(&mylist, ft_lstnew("node 6"));
// 	ft_lstadd_back(&mylist, ft_lstnew("node 7"));
// 	// ft_lstdelone(mylist, danon);
// 	ft_lstiter(mylist, print);
// 	// printf("%s", (char *)mylist->content);
// 	printf("-----------------------------------------\n");
// 	t_list *new_list = NULL;
// 	new_list = ft_lstmap(mylist, content, danon);
// 	ft_lstiter(new_list, print);
// }

char	myfunction(unsigned int i, char ch)
{
	if (i % 2 == 0)
		return (ch - 32);
	return (ch);
}

int	main(void)
{
	int i = 0;
	if (i)
		printf("hello\n");
}