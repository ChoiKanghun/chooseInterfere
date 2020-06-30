/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:14:35 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 15:06:21 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_w_cnt(char const *s, char c)
{
	size_t w_cnt;
	size_t index;
	size_t in_word;

	w_cnt = 0;
	index = 0;
	in_word = 0;
	while (s[index])
	{
		if (s[index] != c && in_word == 0)
		{
			w_cnt++;
			in_word = 1;
		}
		if (s[index] != c)
			in_word = 1;
		if (s[index] == c)
			in_word = 0;
		index++;
	}
	return (w_cnt);
}

static void		init(size_t *index, size_t *j, size_t *len)
{
	*index = 0;
	*j = 0;
	*len = 0;
}

static void		alloc_idx(char **result, char const *s, char c, size_t w_cnt)
{
	char	*each_result;
	size_t	index;
	size_t	j;
	size_t	len;

	init(&index, &j, &len);
	while (j < w_cnt)
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

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	w_cnt;

	if (!s)
		return (NULL);
	w_cnt = get_w_cnt(s, c);
	if (!(result = (char **)ft_calloc(sizeof(char *), (w_cnt + 1))))
		return (NULL);
	alloc_idx(result, s, c, w_cnt);
	return (result);
}
