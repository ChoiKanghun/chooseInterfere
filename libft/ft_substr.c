#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*dest;

	s_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start > s_len)
		return (NULL);
	while (s[i + start] && i < len)
		i++;
	if (!(dest = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		dest[i] = s[i + start];
		i++;
	}
	return (dest);
}	
