#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		iter = temp->next;
		if (del)
			del(temp->content);
		free(temp);
		temp = iter;
	}
	*lst = 0;
}
