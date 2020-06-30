/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:11:42 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/27 22:18:26 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *curr;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		curr = ft_lstlast(*lst);
		if (curr != NULL)
			curr->next = new;
	}
}
