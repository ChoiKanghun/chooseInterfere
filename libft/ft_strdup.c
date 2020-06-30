/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:15:31 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 14:15:48 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	strlen;
	char	*dest;

	strlen = ft_strlen(str);
	if (!(dest = ft_calloc(sizeof(char), strlen + 1)))
		return (NULL);
	ft_memcpy(dest, str, strlen);
	return (dest);
}
