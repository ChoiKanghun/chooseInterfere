/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:13:43 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 14:13:43 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (!s1 && !s2)
		return (0);
	if (n <= 0)
		return (0);
	while (index + 1 < n)
	{
		if (((t_uchar *)s1)[index] != ((t_uchar *)s2)[index])
			return (((t_uchar *)s1)[index] - (((t_uchar *)s2)[index]));
		index++;
	}
	return (((t_uchar *)s1)[index] - ((t_uchar *)s2)[index]);
}
