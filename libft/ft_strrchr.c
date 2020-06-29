#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	if (!s)
		return (ptr);
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = &((char *)s)[i];
		i++;
	}
	if (s[i] == (char)c)
		ptr = &((char *)s)[i];
	return (ptr);
}
