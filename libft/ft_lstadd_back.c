#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		curr = ft_lstlast(*lst);
		curr->next = new;
	}
}
