#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst)
	{
		temp = lst;
		lst = lst->next;
		if (del)
			del(temp->content);
		free(temp);
	}
}
