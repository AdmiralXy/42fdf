#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iter;

	if (*lst != 0)
	{
		iter = *lst;
		while (iter->next != 0)
		{
			iter = iter->next;
		}
		iter->next = new;
	}
	else
		*lst = new;
}
