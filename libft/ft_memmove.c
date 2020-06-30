/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:13:45 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/12 17:36:09 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	t_uchar			*dest;
	const t_uchar	*source;

	dest = (t_uchar *)dst;
	source = (const t_uchar *)src;
	if (!dst && !src)
		return (NULL);
	index = 0;
	if (source < dest)
		while (index < len)
		{
			dest[len - index - 1] = source[len - index - 1];
			index++;
		}
	else
	{
		while (index < len)
		{
			dest[index] = source[index];
			index++;
		}
	}
	return (dst);
}
