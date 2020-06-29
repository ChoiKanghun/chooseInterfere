#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst)
		return ;
	curr = lst;
	while (curr != NULL)
	{
		(*f)(curr->content);
		curr = curr->next;
	}
}
