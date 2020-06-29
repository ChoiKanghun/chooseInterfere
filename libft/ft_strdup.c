#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	strlen;
	char	*dest;

	strlen = ft_strlen(str);
	if (!(dest = ft_calloc(sizeof(char), strlen + 1)))
		return (NULL);
	ft_memcpy(dest, str, strlen);
	return (dest);
}
