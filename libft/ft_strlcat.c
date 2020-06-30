/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:07:12 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 14:16:02 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_index;
	size_t	src_size;
	size_t	result;

	dest_size = ft_strlen((const char *)dst);
	src_size = ft_strlen(src);
	if (dest_size > size)
		result = size;
	else
		result = dest_size;
	src_index = 0;
	while (src[src_index] != '\0' && size > dest_size + src_index + 1)
	{
		dst[dest_size + src_index] = src[src_index];
		src_index++;
	}
	dst[dest_size + src_index] = '\0';
	return (src_size + result);
}
