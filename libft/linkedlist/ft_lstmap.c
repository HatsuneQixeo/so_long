/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:04:57 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/13 17:05:00 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*ft)(void *), void (*del)(void *))
{
	t_list	*lst_main;
	t_list	*node_main;

	if (!lst)
		return (0);
	lst_main = 0;
	while (lst)
	{
		node_main = ft_lstnew(ft(lst->content));
		if (!node_main)
		{
			ft_lstdelone(node_main, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&lst_main, node_main);
	}
	return (lst_main);
}
