#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list *result;

	if (!(result = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
