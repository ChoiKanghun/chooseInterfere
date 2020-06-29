#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < len)
	{
		((t_uchar *)dst)[i] = ((t_uchar *)src)[i];
		if (((t_uchar *)dst)[i] == (t_uchar)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);	
}
