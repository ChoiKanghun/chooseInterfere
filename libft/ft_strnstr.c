#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	while (len)
	{
		if (little[j] == '\0')
			return (&((char *)big)[i - j]);
		if (little[j] == big[i])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (i >= len || big[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
