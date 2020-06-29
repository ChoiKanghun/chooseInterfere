#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int	size;
	
	size = 0;
	curr = lst;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
