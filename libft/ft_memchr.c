/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:13:42 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 17:05:38 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((t_uchar *)s)[i] == (t_uchar)c)
			return ((t_uchar *)s + i);
		i++;
	}
	return (NULL);
}
