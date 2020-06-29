#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	if (!(unsigned char *)b)
		return (NULL);
	while (i < len)
	{
		((t_uchar *)b)[i] = (t_uchar)c;
		i++;
	}
	return (b);
}
