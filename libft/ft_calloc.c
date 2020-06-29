#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*dest;

	if (!(dest = (void *)malloc(number * size)))
		return (NULL);
	ft_bzero(dest, number * size);
	return (dest);
}
