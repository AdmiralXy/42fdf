#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*temp;

	new_lst = 0;
	temp = lst;
	while (temp)
	{
		new_elem = ft_lstnew(f(temp->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_elem);
		temp = temp->next;
	}
	return (new_lst);
}
