#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	t_uchar		*dest;
	const t_uchar	*source;

	dest = (t_uchar *)dst;
	source = (const t_uchar *)src;
	if (!dst && !src)
		return (NULL);
	index = 0;
	if (source < dest)
		while (index < len)
		{
			dest[len - index - 1] = source[len - index - 1];
			index++;
		}
	else
	{
		while (index < len)
		{
			dest[index] = source[index];
			index++;
		}
	}
	return (dst);
}
