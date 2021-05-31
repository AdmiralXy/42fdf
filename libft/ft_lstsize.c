#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*iter;

	i = 0;
	iter = lst;
	while (iter != 0)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
