#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*curr_new;
	t_list	*curr_old;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	curr_new = new;
	curr_old = lst->next;
	while (curr_old != NULL)
	{
		if (!(curr_new->next = ft_lstnew((*f)(curr_old->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		curr_new = curr_new->next;
		curr_old = curr_old->next;
	}
	return (new);
}
