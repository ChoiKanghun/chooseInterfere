/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:13:08 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/27 22:27:07 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*curr_new;
	t_list	*curr_old;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	curr_new = new;
	curr_old = lst->next;
	while (curr_old != NULL)
	{
		if (!(curr_new->next = ft_lstnew((*f)(curr_old->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		curr_new = curr_new->next;
		curr_old = curr_old->next;
	}
	return (new);
}
