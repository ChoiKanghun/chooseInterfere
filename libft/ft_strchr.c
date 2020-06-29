#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)s + i);
		i++;
	}
	if ((char)c == ((char *)s)[i])
		return ((char *)s + i);
	return (NULL);
}
