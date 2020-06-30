/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchoi <kchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:13:11 by kchoi             #+#    #+#             */
/*   Updated: 2020/04/11 14:26:34 by kchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		size;

	size = 0;
	curr = lst;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
