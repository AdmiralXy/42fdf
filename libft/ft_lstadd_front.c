#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != 0)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
