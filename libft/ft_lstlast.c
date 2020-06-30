/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:13:07 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/27 22:17:31 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->next == NULL)
			return (curr);
		curr = curr->next;
	}
	return (curr);
}
