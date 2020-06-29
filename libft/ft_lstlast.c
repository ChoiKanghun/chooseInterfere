#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->next == NULL)
			return (curr);
		curr = curr->next;	
	}
	return (curr);
}
