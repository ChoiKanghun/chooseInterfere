#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t count)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < count)
	{
		if (((t_uchar *)s)[i] == (t_uchar)c)
			return ((t_uchar *)s + i);
		i++;
	}
	return (NULL);
}
