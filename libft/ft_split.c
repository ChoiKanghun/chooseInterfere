#include "libft.h"

static size_t	get_word_count(char const *s, char c)
{
	size_t word_count;
	size_t index;
	size_t in_word;

	word_count = 0;
	index = 0;
	in_word = 0;
	while (s[index])
	{
		if (s[index] != c && in_word == 0)
		{
			word_count++;
			in_word = 1;
		}
		if (s[index] != c)
			in_word = 1;
		if (s[index] == c)
			in_word = 0;
		index++;
	}
	return (word_count);
}

static void	init(size_t *index, size_t *j, size_t *len)
{
	*index = 0;
	*j = 0;
	*len = 0;
}

static void	allocate_each_index(char **result, char const *s, char c, size_t word_count)
{
	char	*each_result;
	size_t	index;
	size_t	j;
	size_t	len;

	init(&index, &j, &len);
	while (j < word_count)
	{
		if (s[index] == c || !s[index])
		{
			if (len != 0)
			{
				if (!(each_result = ft_calloc(sizeof(char), len + 1)))
					return ;
				ft_memcpy(each_result, s + index - len, len);
				result[j] = each_result;
				j++;
			}
			len = 0;
		}
		else
			len++;
		index++;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	word_count = get_word_count(s, c);
	if (!(result = (char **)ft_calloc(sizeof(char *), (word_count + 1))))
		return (NULL);
	allocate_each_index(result, s, c, word_count);
	return (result);
}
