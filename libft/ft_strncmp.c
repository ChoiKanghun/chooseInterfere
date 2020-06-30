/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:16:30 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 14:16:55 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t i;

	if ((!s1 && !s2) || len <= 0)
		return (0);
	i = 0;
	while (i < len && (s1[i] && s2[i]))
	{
		if (((t_uchar *)s1)[i] != ((t_uchar *)s2)[i])
			return (((t_uchar *)s1)[i] - ((t_uchar *)s2)[i]);
		i++;
	}
	if (i == len)
		return (0);
	else
		return (((t_uchar *)s1)[i] - ((t_uchar *)s2)[i]);
}
