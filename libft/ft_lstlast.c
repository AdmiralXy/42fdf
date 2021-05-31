#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	if (!lst)
		return (0);
	iter = lst;
	while (iter->next != 0)
	{
		iter = iter->next;
	}
	return (iter);
}
