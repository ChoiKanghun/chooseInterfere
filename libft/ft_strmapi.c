#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char		*dest;
	size_t		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (!(dest = ft_calloc(sizeof(char), s_len + 1)))
		return (NULL);
	while (s[i])
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
