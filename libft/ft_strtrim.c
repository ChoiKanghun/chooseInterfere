#include "libft.h"

static int	if_word_in_str(const char c, const char *set)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_index(const char *s1, const char *set, int flag)
{
	size_t	i;
	size_t	jndex;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = 0;
	if (s1_len == 0)
		return (0);
	while (s1[i])
	{
		jndex = i;
		if (flag < 0)
			jndex = s1_len - 1 - i;
		if (!if_word_in_str(s1[jndex], set))
			return (jndex);
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = get_index(s1, set, 1);
	end = get_index(s1, set, -1);
	if (!(dest = ft_calloc(sizeof(char), end - start + 1)))
		return (NULL);
	ft_memcpy(dest, s1 + start, end - start + 1);
	return (dest);
}
