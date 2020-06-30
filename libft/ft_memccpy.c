/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:13:40 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 14:27:09 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < len)
	{
		((t_uchar *)dst)[i] = ((t_uchar *)src)[i];
		if (((t_uchar *)dst)[i] == (t_uchar)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
