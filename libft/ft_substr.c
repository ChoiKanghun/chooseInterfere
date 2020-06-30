/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:17:30 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/27 22:11:05 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		if (!(dest = ft_calloc(sizeof(char), 1)))
			return (NULL);
		return (dest);
	}
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
